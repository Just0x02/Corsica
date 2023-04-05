#include <corsica/mesh.hpp>
#include <corsica/debugger.hpp>
#include <corsica/corsica.hpp>

using namespace Corsica;

Mesh::Mesh(const std::string &vs_shader_path, const std::string &fs_shader_path, const std::string &tex_path)
{
    this->mesh_shader = Shader::create(
        vs_shader_path.c_str(), 
        fs_shader_path.c_str(),
        {}
    );

    this->mesh_texture = Texture2D::create_from_path(
        (char *) tex_path.c_str()
    );
}


Mesh::Mesh(Shader mesh_shader, Texture2D mesh_texture) : mesh_shader(mesh_shader), mesh_texture(mesh_texture)
{

}

Mesh::~Mesh()
{
    this->destroy_mesh();
}

void Mesh::destroy_mesh()
{
    Corsica::MESH_LOGGER.warn("Destroying mesh shader & texture...");
    Shader::destroy(this->mesh_shader);
    Texture2D::destroy(this->mesh_texture);
    Corsica::MESH_LOGGER.warn("Destroyed mesh shader & texture.");
}

void Mesh::draw_mesh()
{
    if (this->config.use_wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Shader::use(this->mesh_shader);
    VAO::bind(this->vao);
    glDrawElements(GL_TRIANGLES, this->mesh_data.indices.size(), GL_UNSIGNED_INT, 0);
    // glDrawArrays(GL_TRIANGLES, 0, (size_t) (this->mesh_data.vertices.size() / this->mesh_data.vertex_size));
}