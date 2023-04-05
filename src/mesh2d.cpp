#include <corsica/mesh2d.hpp>

#include <iostream>

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

    std::cout << "[CORSICA][DEBUG][MESH2D] Sucessfully compiled mesh with " << (this->mesh_data.vertices.size() / Mesh2D::VERTEX_SIZE) << " vertice(s)." << std::endl;

    return this->mesh_data;
}