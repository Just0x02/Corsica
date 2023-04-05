#include <corsica/meshdata.hpp>

using namespace Corsica;

std::vector<Vertex> MeshData::generate_vertices()
{
    std::vector<Vertex> vs;

    size_t total_verticies = this->vertices.size() / this->vertex_size;

    vs.reserve(total_verticies);

    for (i32 i = 0; i < total_verticies; i++)
    {
        f32 x, y, z;
        f32 r, g, b, a;
        f32 tex_x, tex_y;

        x = this->vertices[(i * this->vertex_size) + 0];
        y = this->vertices[(i * this->vertex_size) + 1];
        
        if (this->vertex_size >= 3)
            z = this->vertices[(i * this->vertex_size) + 2];

        r = this->colors[(i * this->color_size) + 0];
        g = this->colors[(i * this->color_size) + 1];
        b = this->colors[(i * this->color_size) + 2];
        a = this->colors[(i * this->color_size) + 3];

        tex_x = this->tex_coords[(i * this->tex_coord_size) + 0];
        tex_y = this->tex_coords[(i * this->tex_coord_size) + 1];

        vs.push_back((Vertex) {
            .position  = { x, y, z },
            .color     = { r, g, b, a },
            .tex_coord = { tex_x, tex_y }
        });
    }

    return vs;
}

MeshData &MeshData::add_vertex(Vertex &vert)
{
    this->vertices.push_back(vert.position.x);
    this->vertices.push_back(vert.position.y);
    this->vertices.push_back(vert.position.z);

    this->colors.push_back(vert.color.x);
    this->colors.push_back(vert.color.y);
    this->colors.push_back(vert.color.z);
    this->colors.push_back(vert.color.w);

    this->tex_coords.push_back(vert.tex_coord.x);
    this->tex_coords.push_back(vert.tex_coord.y);

    return *this;
}

MeshData &MeshData::clear()
{
    this->vertices.clear();
    this->indices.clear();
    this->tex_coords.clear();
    this->colors.clear();

    return *this;
}