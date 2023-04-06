#pragma once

#include <types.h>

#include <corsica/gfx.hpp>
#include <corsica/vec2.hpp>
#include <corsica/image.hpp>

#include <string>

namespace Corsica
{
    struct Texture2D
    {
        GLuint handle;
        Vec2 size;
        Vec2 uv_unit;

        static Texture2D create_from_pixels(u32 *pixels, size_t width, size_t height);
        static Texture2D create_from_image(Image &image);
        static Texture2D create_from_path(std::string path);
        
        static void destroy(const Texture2D &tex);
        static void bind(const Texture2D &tex);
    };
};