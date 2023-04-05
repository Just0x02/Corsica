#include <corsica/fio.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


using namespace Corsica;

bool FileIO::directory_exists(const char *dir_path)
{
    if (dir_path == NULL) return false;

    struct stat st;
    return stat(dir_path,&st) == 0 && st.st_mode & S_IFDIR != 0;
}

bool FileIO::create_directory(const char *dir_path)
{
    return mkdir(dir_path, 0777);
}

bool FileIO::create_file(const char *file_path)
{
    FILE *fp;

    if (fp = fopen(file_path, "w"))
    {
        fclose(fp);
        return true;
    }
    
    return false;
}

bool FileIO::file_exists(const char *file_path)
{
    FILE *fp;

    if (fp = fopen(file_path, "r"))
    {
        fclose(fp);
        return true;
    }

    return false;
}

std::string FileIO::read_file(const char *file_path)
{
    std::string file_data;
    std::ifstream file_stream(file_path, std::ios::in);

    if(!file_stream.is_open()) 
    {
        std::cerr << "Could not read file " << file_path << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!file_stream.eof()) 
    {
        std::getline(file_stream, line);
        file_data.append(line + "\n");
    }

    file_stream.close();
    return file_data;
}

