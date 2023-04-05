#pragma once

#include <types.h>

#include <corsica/gfx.hpp>

namespace Corsica
{
    struct VAO
    {
        GLuint handle;

        void bind();
        void destroy();
        void attribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset);
        // void format(GLuint index, GLint size, GLenum type, GLboolean normalized, GLuint offset);

        static VAO create();

        static void destroy(VAO &vao);
        static void bind(VAO &vao);
        static void attribute(VAO &vao, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset);
        // static void format(VAO &vao, GLuint index, GLint size, GLenum type, GLboolean normalized, GLuint offset);

        static void unbind();
    };
};