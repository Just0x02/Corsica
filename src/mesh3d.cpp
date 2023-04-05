#include <corsica/mesh3d.hpp>
#include <corsica/corsica.hpp>

using namespace Corsica;

Mesh3D::Mesh3D(const std::string &vs_shader_path, const std::string &fs_shader_path, const std::string &tex_path) : Mesh(vs_shader_path, fs_shader_path, tex_path)
{

}

Mesh3D::Mesh3D(Shader mesh_shader, Texture2D mesh_texture) : Mesh(mesh_shader, mesh_texture)
{

}

Mesh3D::~Mesh3D()
{

}

MeshData &Mesh3D::compile_mesh()
{
    this->mesh_data.vertices = {
        -1, -1,  0.5, //0
         1, -1,  0.5, //1
        -1,  1,  0.5, //2
         1,  1,  0.5, //3
        -1, -1, -0.5, //4
         1, -1, -0.5, //5
        -1,  1, -0.5, //6
         1,  1, -0.5  //7
    };  

    this->mesh_data.indices = {
        //Top
        2, 6, 7,
        2, 3, 7,

        //Bottom
        0, 4, 5,
        0, 1, 5,

        //Left
        0, 2, 6,
        0, 4, 6,

        //Right
        1, 3, 7,
        1, 5, 7,

        //Front
        0, 2, 3,
        0, 1, 3,

        //Back
        4, 6, 7,
        4, 5, 7
    };

    if (this->mesh_data.vertices.size() == 0)
        Corsica::MESH_LOGGER.warn("Attempting to compile a mesh with no vertices, is this a mistake?");

    this->mesh_data.vertex_size = Mesh3D::VERTEX_SIZE;

    this->vao = VAO::create();
    this->vbo = VBO::create(GL_ARRAY_BUFFER, false);
    this->ebo = EBO::create(GL_ELEMENT_ARRAY_BUFFER, false);

    VAO::bind(this->vao);

    VBO::bind(this->vbo);
    VBO::buffer(this->vbo, this->mesh_data.vertices, this->mesh_data.vertices.size());
    
    EBO::bind(this->ebo);
    EBO::buffer(this->ebo, this->mesh_data.indices, this->mesh_data.indices.size());

    glVertexAttribPointer(0, this->mesh_data.vertex_size, GL_FLOAT, GL_FALSE, this->mesh_data.vertex_size * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(0);

    VBO::unbind();
    VAO::unbind();

    Corsica::MESH_LOGGER.debug("Sucessfully compiled 3d mesh with ", (this->mesh_data.vertices.size() / Mesh3D::VERTEX_SIZE), " vertices(s).");

    return this->mesh_data;
}