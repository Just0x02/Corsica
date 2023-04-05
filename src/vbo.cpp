#include <corsica/vbo.hpp>

using namespace Corsica;

VBO VBO::create(GLint type, bool dynamic)
{
    VBO vbo;

    vbo.type = type;
    vbo.dynamic = dynamic;

    glGenBuffers(1, &vbo.handle);

    return vbo;
}

void VBO::destroy(const VBO &vbo)
{
    glDeleteBuffers(1, &vbo.handle);
}

void VBO::bind(const VBO &vbo)
{
    glBindBuffer(vbo.type, vbo.handle);
}

void VBO::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::buffer(const VBO &vbo, std::vector<f32> &data, size_t count)
{
    glBufferData(vbo.type, count * sizeof(f32), &data.data()[0], vbo.dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}

void VBO::destroy()
{
    VBO::destroy(*this);
}

void VBO::bind()
{
    VBO::bind(*this);
}

void VBO::buffer(std::vector<f32> &data, size_t count)
{
    VBO::buffer(*this, data, count);
}
