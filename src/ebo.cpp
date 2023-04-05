#include <corsica/ebo.hpp>

using namespace Corsica;

EBO EBO::create(GLint type, bool dynamic)
{
    EBO ebo;

    ebo.type = type;
    ebo.dynamic = dynamic;

    glGenBuffers(1, &ebo.handle);

    return ebo;
}

void EBO::destroy(EBO &ebo)
{
    glDeleteVertexArrays(1, &ebo.handle);
}

void EBO::bind(EBO &ebo)
{
    glBindBuffer(ebo.type, ebo.handle);
}

void EBO::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::buffer(EBO &ebo, std::vector<u32> &data, size_t count)
{
    glBufferData(ebo.type, count * sizeof(u32), &data.data()[0], ebo.dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}

void EBO::bind()
{
    EBO::bind(*this);
}

void EBO::destroy()
{
    EBO::destroy(*this);
}

void EBO::buffer(std::vector<u32> &data, size_t count)
{
    EBO::buffer(*this, data, count);
}
