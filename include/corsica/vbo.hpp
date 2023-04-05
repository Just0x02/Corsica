#pragma once

#include <types.h>
#include <corsica/gfx.hpp>

#include <corsica/vertex.hpp>
#include <vector>

namespace Corsica
{
    struct VBO
    {
        GLuint handle;
        GLint type;
        bool dynamic;

        void destroy();
        void bind();
        void buffer(std::vector<f32> &data, size_t count);

        static VBO create(GLint type, bool dynamic);

        static void destroy(const VBO &vbo);
        static void bind(const VBO &vbo);
        static void buffer(const VBO &vbo, std::vector<f32> &data, size_t count);

        static void unbind();
    };
};