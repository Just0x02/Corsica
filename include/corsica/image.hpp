#pragma once

#include <types.h>
#include <string>


namespace Corsica
{
    struct Image
    {
        std::string file_path;

        u32 *pixels;
        i32 width, height, channels;

        Image(std::string src_file_paths);
        Image();
        ~Image();

        u64 get_size();
        u64 get_pixels_size();

        void load();

        void load_from_file(const std::string &img_path);
        void write_to_file(const std::string &new_img_path);
    };
};