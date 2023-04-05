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

void VAO::attribute(VAO &vao, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset)
{
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized, stride, offset);
}