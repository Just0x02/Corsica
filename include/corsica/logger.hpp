#pragma once

#include <types.h>
#include <corsica/rgb.hpp>
#include <string>

#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>

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

            const Logger &info(const std::string &s);
            const Logger &debug(const std::string &s);
            const Logger &warn(const std::string &s);
            const Logger &error(const std::string &s);
            const Logger &fatal(const std::string &s);

            template <typename T, typename... VT>
            const Logger &info(const std::string &s, T arg_first, VT... args);
            template <typename T, typename... VT>
            const Logger &debug(const std::string &s, T arg_first, VT... args);
            template <typename T, typename... VT>
            const Logger &warn(const std::string &s, T arg_first, VT... args);
            template <typename T, typename... VT>
            const Logger &error(const std::string &s, T arg_first, VT... args);
            template <typename T, typename... VT>
            const Logger &fatal(const std::string &s, T arg_first, VT... args);

            const Logger &log(u8 log_level, const std::string &s);

            Logger &set_log_flags(u64 flags);

            static RGB get_color_for_level(u8 log_level);
            static const std::string generate_log_prefix(u64 log_flags);
            static const std::string get_str_of_log_level(u8 log_level);
            static const std::string get_date_str();
            static std::ofstream open_log_file_stream(std::string log_dir, std::string log_file);
            static void log_static(u8 log_level, u64 log_flags, const std::string &s);
    };


    template <typename T, typename... VT>
    const Logger &Logger::info(const std::string &s, T arg_first, VT... args)
    {
        std::stringstream ss;
        ss << s << arg_first;
        return this->info(ss.str(), args...);
    }

    template <typename T, typename... VT>
    const Logger &Logger::debug(const std::string &s, T arg_first, VT... args)
    {
        std::stringstream ss;
        ss << s << arg_first;
        return this->debug(ss.str(), args...);
    }

    template <typename T, typename... VT>
    const Logger &Logger::warn(const std::string &s, T arg_first, VT... args)
    {
        std::stringstream ss;
        ss << s << arg_first;
        return this->warn(ss.str(), args...);
    }

    template <typename T, typename... VT>
    const Logger &Logger::error(const std::string &s, T arg_first, VT... args)
    {
        std::stringstream ss;
        ss << s << arg_first;
        return this->error(ss.str(), args...);
    }

    template <typename T, typename... VT>
    const Logger &Logger::fatal(const std::string &s, T arg_first, VT... args)
    {
        std::stringstream ss;
        ss << s << arg_first;
        return this->fatal(ss.str(), args...);
    }
};