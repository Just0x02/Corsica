#pragma once

#include <types.h>
#include <string>
#include <dirent.h>

namespace Corsica::FileIO
{
    std::string read_file(const char *file_path);
    bool create_directory(const char *dir_path);
    bool create_file(const char *file_path);
    bool directory_exists(const char *dir_path);
    bool file_exists(const char *file_path);
};