#pragma once

#include <types.h>
#include <string>


namespace Corsica
{
    struct Image
    {
        std::string file_path;

        u8 *pixels;
        i32 width, height, channels;

        Image(std::string src_file_paths);
        ~Image();

        void load();
    };
};