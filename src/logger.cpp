#include <corsica/logger.hpp>
#include <corsica/fio.hpp>

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace Corsica;

extern u64 Logging::LOG_KEY  = Logging::DEFAULT_KEY_FLAGS;
extern u8 Logging::LOG_LEVEL = LogLevel::ALL;

const std::string Logger::generate_log_prefix(u64 log_flags)
{
    std::string log_prefix;

    if (LogFlag::CORSICA & log_flags)
        log_prefix += "[CORSICA]";
    
    if (LogFlag::SHADERS & log_flags)
        log_prefix += "[SHADERS]";
    else if (LogFlag::WINDOW & log_flags)
        log_prefix += "[WINDOW]";
    else if (LogFlag::OPENGL & log_flags)
        log_prefix += "[OPENGL]";
    else if (LogFlag::FILEIO & log_flags)
        log_prefix += "[FILEIO]";
    else if (LogFlag::TEXTURE & log_flags)
        log_prefix += "[TEXTURE]";
    else if (LogFlag::MESH & log_flags)
        log_prefix += "[MESH]";
    else if (LogFlag::EVENT & log_flags)
        log_prefix += "[EVENT]";

    return log_prefix;
}

std::ofstream Logger::open_log_file_stream(std::string log_dir, std::string log_file)
{
    std::string true_log_file_path = log_dir + "/" + log_file;

    if (!FileIO::directory_exists(log_dir.c_str()))
        FileIO::create_directory(log_dir.c_str());

    if (!FileIO::file_exists(true_log_file_path.c_str()))
        FileIO::create_file(true_log_file_path.c_str());
        

    std::ofstream file_stream;
    
    file_stream.open(true_log_file_path);

    return file_stream;
}

Logger::Logger(std::string log_dir, std::string log_file)
{
    this->file_stream = Logger::open_log_file_stream(log_dir, log_file);
    this->do_color = this->do_color_lexing = true;
}

Logger::Logger(std::string log_file)
{
    this->file_stream = Logger::open_log_file_stream(__CORSICA_DEFAULT_LOG_DIR, log_file);
    this->do_color = this->do_color_lexing = true;
}

Logger::Logger(u64 log_flag)
{
    this->set_log_flags(log_flag);
    this->file_stream = Logger::open_log_file_stream(__CORSICA_DEFAULT_LOG_DIR, __CORSICA_DEFAULT_LOG_FILE);
    this->do_color = this->do_color_lexing = true;
}

Logger::~Logger()
{
    this->file_stream.close();
}

Logger &Logger::info(const std::string &s)
{
    return this->log(LogLevel::INFO, s);
}

Logger &Logger::debug(const std::string &s)
{
    return this->log(LogLevel::DEBUG, s);
}

Logger &Logger::warn(const std::string &s)
{
    return this->log(LogLevel::WARNING, s);
}

Logger &Logger::error(const std::string &s)
{
    return this->log(LogLevel::ERROR, s);
}

Logger &Logger::fatal(const std::string &s)
{
    return this->log(LogLevel::FATAL, s);
}

Logger &Logger::log(u8 log_level, const std::string &s)
{
    if (log_level <= Logging::LOG_LEVEL)
    {
        std::string date_str = Logger::get_date_str();
        std::string level_str = Logger::get_str_of_log_level(log_level);
        this->file_stream << date_str << level_str << this->log_prefix << " " << s << std::endl;

        if (this->do_color)
            std::cout << Logger::get_color_for_level(log_level).as_escape_code();
        std::cout << date_str << level_str << this->log_prefix << " " << s << std::endl << "\033[0;0m";
    }

    return *this;
}

const std::string Logger::get_str_of_log_level(u8 log_level)
{
    switch (log_level)
    {
        case LogLevel::INFO: return "[INFO]";
        case LogLevel::ERROR: return "[ERROR]";
        case LogLevel::FATAL: return "[FATAL]";
        case LogLevel::WARNING: return "[WARNING]";
        case LogLevel::DEBUG: return "[DEBUG]";
        case LogLevel::ALL: return "[ALL]";
        default: return "[*]";
    }
}

const std::string Logger::get_date_str()
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);

    std::stringstream ss;
    ss.imbue(std::locale("en_US.utf8"));
    ss << std::put_time(&tm, "%T");

    return "[" + ss.str() + "]";
}

RGB Logger::get_color_for_level(u8 log_level)
{
    switch (log_level)
    {
        case LogLevel::INFO: return RGB(0x347aeb);
        case LogLevel::ERROR: return RGB(0xe62517);
        case LogLevel::FATAL: return RGB(0xa30d02);
        case LogLevel::WARNING: return RGB(0xf0d316);
        case LogLevel::DEBUG: return RGB(0xd609b4);
        default: return __CORSICA_WHITE;
    }
}

Logger &Logger::set_log_flags(u64 log_flags)
{
    this->log_flags = log_flags;
    this->log_prefix = Logger::generate_log_prefix(this->log_flags);

    return *this;
}

void Logger::log_static(u8 log_level, u64 log_flags, const std::string &s)
{
    if (log_level <= Logging::LOG_LEVEL)
    {
        std::string date_str = Logger::get_date_str();
        std::string log_level_str = Logger::get_str_of_log_level(log_level);
        std::string log_prefix = Logger::generate_log_prefix(log_flags);
        std::ofstream log_stream = Logger::open_log_file_stream(__CORSICA_DEFAULT_LOG_DIR, __CORSICA_DEFAULT_LOG_FILE);

        log_stream << date_str << log_level_str << log_prefix << " " << s << std::endl;
        std::cout << date_str << log_level_str << log_prefix << " " << s << std::endl;

        log_stream.close();
    }
}