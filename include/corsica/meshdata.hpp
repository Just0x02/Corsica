#pragma once

#include <types.h>

#include <corsica/vertex.hpp>
#include <vector>

namespace Corsica
{
    struct MeshData
    {
        std::vector<f32> vertices;
        std::vector<f32> colors;
        std::vector<f32> tex_coords;
        std::vector<u32> indices;

        u32 vertex_size, color_size, tex_coord_size;

        std::vector<Vertex> generate_vertices();
        MeshData &add_vertex(Vertex &vert);
        MeshData &clear();
    };
};