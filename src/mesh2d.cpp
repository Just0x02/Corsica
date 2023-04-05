#include <corsica/mesh2d.hpp>
#include <corsica/corsica.hpp>

using namespace Corsica;

Mesh2D::Mesh2D()
{

}

Mesh2D::Mesh2D(const std::string &vs_shader_path, const std::string &fs_shader_path, std::vector<VertexAttr> attributes, const std::string &tex_path) : Mesh(vs_shader_path, fs_shader_path, attributes, tex_path)
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
        0.5f,  0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f,  0.5f,
    };

    this->mesh_data.indices = {
        0, 1, 3,
        1, 2, 3 
    };

    this->mesh_data.tex_coords = {
        1.0f, 1.0f, // top right
        1.0f, 0.0f, // bottom right
        0.0f, 0.0f, // bottom left
        0.0f, 1.0f  // top left 
    };

    if (this->mesh_data.vertices.size() == 0)
        Corsica::MESH_LOGGER.warn("Attempting to compile a mesh with no vertices, is this a mistake?");

    this->mesh_data.vertex_size    = Mesh2D::VERTEX_SIZE;
    this->mesh_data.color_size     = 4;
    this->mesh_data.tex_coord_size = 2;

    this->vao = VAO::create();
    this->vbo = VBO::create(GL_ARRAY_BUFFER, false);
    this->ebo = EBO::create(GL_ELEMENT_ARRAY_BUFFER, false);

    VAO::bind(this->vao);

    VBO::bind(this->vbo);
    VBO::buffer(this->vbo, this->mesh_data.vertices, this->mesh_data.vertices.size());
    
    EBO::bind(this->ebo);
    EBO::buffer(this->ebo, this->mesh_data.indices, this->mesh_data.indices.size());

    // position attribute
    glVertexAttribPointer(0, this->mesh_data.vertex_size, GL_FLOAT, GL_FALSE, this->mesh_data.vertex_size * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, this->mesh_data.color_size, GL_FLOAT, GL_FALSE, this->mesh_data.color_size * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(1);

    // texture coord attribute
    glVertexAttribPointer(2, this->mesh_data.tex_coord_size, GL_FLOAT, GL_FALSE, this->mesh_data.tex_coord_size * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(2);

    VBO::unbind();
    VAO::unbind();

    Corsica::MESH_LOGGER.debug("Sucessfully compiled 2d mesh with ", (this->mesh_data.vertices.size() / Mesh2D::VERTEX_SIZE), " vertices(s).");

    return this->mesh_data;
}