#pragma once

#include <types.h>


namespace Corsica
{
    struct Image
    {
        char *file_path;

        u8 *pixels;
        i32 width, height, channels;

        Image(const char *src_file_paths);
        ~Image();

        void load();
    };
};