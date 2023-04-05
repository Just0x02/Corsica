#include <corsica/mesh2d.hpp>
#include <corsica/corsica.hpp>

using namespace Corsica;

Mesh2D::Mesh2D(const std::string &vs_shader_path, const std::string &fs_shader_path, const std::string &tex_path) : Mesh(vs_shader_path, fs_shader_path, tex_path)
{

}

Mesh2D::Mesh2D(Shader mesh_shader, Texture2D mesh_texture) : Mesh(mesh_shader, mesh_texture)
{

}

Mesh2D::~Mesh2D()
{

}

MeshData &Mesh2D::compile_mesh()
{
    this->mesh_data.vertices = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f,  0.5f,
    };

    if (this->mesh_data.vertices.size() == 0)
        Corsica::MESH_LOGGER.warn("Attempting to compile a mesh with no vertices, is this a mistake?");

    this->mesh_data.vertex_size = Mesh2D::VERTEX_SIZE;

    this->vao = VAO::create();
    this->vbo = VBO::create(GL_ARRAY_BUFFER, false);

    VAO::bind(this->vao);
    VBO::bind(this->vbo);

    VBO::buffer(this->vbo, this->mesh_data.vertices, this->mesh_data.vertices.size());

    glVertexAttribPointer(0, this->mesh_data.vertex_size, GL_FLOAT, GL_FALSE, this->mesh_data.vertex_size * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(0);

    VBO::unbind();
    VAO::unbind();

    Corsica::MESH_LOGGER.debug("Sucessfully compiled 2d mesh with ", (this->mesh_data.vertices.size() / Mesh2D::VERTEX_SIZE), " vertices(s).");

    return this->mesh_data;
}