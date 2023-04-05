#pragma once

#include <types.h>
#include <corsica/rgb.hpp>
#include <string>

#include <fstream>

#define __CORSICA_DEFAULT_LOG_DIR  "./data"
#define __CORSICA_DEFAULT_LOG_FILE "log-newest.txt"

namespace Corsica
{
    enum LogLevel : u8
    {
        FATAL, 
        ERROR, 
        WARNING,
        INFO,
        DEBUG,
        ALL = 0xFF
    };

    enum LogFlag : u64
    {
        CORSICA = 1 << 9,
        SHADERS = 1 << 10,
        WINDOW  = 1 << 11,
        OPENGL  = 1 << 12,
        FILEIO  = 1 << 13,
        TEXTURE = 1 << 14,
        MESH    = 1 << 15,
        EVENT   = 1 << 16
    };

    namespace Logging
    {
        static const u64 DEFAULT_KEY_FLAGS =
                                         LogFlag::CORSICA | 
                                         LogFlag::SHADERS |
                                         LogFlag::WINDOW  |
                                         LogFlag::OPENGL  |
                                         LogFlag::FILEIO  |
                                         LogFlag::TEXTURE |
                                         LogFlag::MESH    |
                                         LogFlag::EVENT;
        extern u64 LOG_KEY;
        extern u8 LOG_LEVEL;
    };

    class Logger
    {
        private:
            std::ofstream file_stream;
            std::string log_prefix;
            u64 log_flags;

        public:
            bool do_color, do_color_lexing;

            Logger(std::string log_dir, std::string log_file);
            Logger(std::string log_file);
            Logger(u64 log_level);
            ~Logger();

            Logger &info(const std::string &s);
            Logger &debug(const std::string &s);
            Logger &warn(const std::string &s);
            Logger &error(const std::string &s);
            Logger &fatal(const std::string &s);

            Logger &log(u8 log_level, const std::string &s);

            Logger &set_log_flags(u64 flags);

            static RGB get_color_for_level(u8 log_level);
            static const std::string generate_log_prefix(u64 log_flags);
            static const std::string get_str_of_log_level(u8 log_level);
            static const std::string get_date_str();
            static std::ofstream open_log_file_stream(std::string log_dir, std::string log_file);
            static void log_static(u8 log_level, u64 log_flags, const std::string &s);
    };
};