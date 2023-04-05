#pragma once

#include <types.h>

#include <corsica/gfx.hpp>

#include <vector>

namespace Corsica
{
    struct EBO
    {
        GLuint handle;
        GLint type;
        bool dynamic;

        void bind();
        void destroy();
        void buffer(std::vector<u32> &data, size_t count);

        static EBO create(GLint type, bool dynamic);

        static void destroy(EBO &ebo);
        static void bind(EBO &ebo);
        static void buffer(EBO &ebo, std::vector<u32> &data, size_t count);

        static void unbind();
        
    };
};