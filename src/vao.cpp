#include <corsica/vao.hpp>

using namespace Corsica;

VAO VAO::create()
{
    VAO vao;

    glGenVertexArrays(1, &vao.handle);

    return vao;
}

void VAO::destroy(VAO &vao)
{
    glDeleteVertexArrays(1, &vao.handle);
}

void VAO::bind(VAO &vao)
{
    glBindVertexArray(vao.handle);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}

void VAO::bind()
{
    VAO::bind(*this);
}

void VAO::destroy()
{
    VAO::destroy(*this);
}

void VAO::attribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset)
{
    VAO::attribute(*this, index, size, type, normalized, stride, offset);
}

// void VAO::format(GLuint index, GLint size, GLenum type, GLboolean normalized, GLuint offset)
// {
//     VAO::format(*this, index, size, normalized, offset);
// }

// void VAO::format(VAO &vao, GLuint index, GLint size, GLenum type, GLboolean normalized, GLuint offset)
// {
//     glBindVertexBuffer(0, vao.handle, offset, sizeof(Vertex));

//     glVertexAttribFormat(index, size, type, normalized, offset);
// }

void VAO::attribute(VAO &vao, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset)
{
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized, stride, offset);

    // VAO::bind(vao_a);
    // VAO::bind(vao_b);

    // NOTE: glVertexAttribPointer will AUTO-CONVERT integer values to floating point.
    // Integer vertex attributes must be specified with glVertexAttribIPointer.
    // THIS IS EVIL. OpenGL is bad. Who designed this to fail silently?
    // switch (type) {
    //     case GL_BYTE:
    //     case GL_UNSIGNED_BYTE:
    //     case GL_SHORT:
    //     case GL_UNSIGNED_SHORT:
    //     case GL_INT:
    //     case GL_UNSIGNED_INT:
    //     case GL_INT_2_10_10_10_REV:
    //     case GL_UNSIGNED_INT_2_10_10_10_REV:
    //         glVertexAttribIPointer(index, size, type, stride, (void *) offset);
    //         break;
    //     default:
    //         glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void *) offset);
    //         break;
    // }

    // glEnableVertexAttribArray(index);
}