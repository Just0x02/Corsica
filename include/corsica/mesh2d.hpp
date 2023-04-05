#pragma once

#include <types.h>

#include <corsica/shader.hpp>
#include <corsica/texture.hpp>

#include <corsica/vao.hpp>
#include <corsica/vbo.hpp>
#include <corsica/ebo.hpp>

#include <corsica/mesh.hpp>

namespace Corsica
{
    struct Mesh2D : Corsica::Mesh
    {
        static const u32 VERTEX_SIZE = 2;

        MeshData &compile_mesh();

        Mesh2D(const std::string &vs_shader_path, const std::string &fs_shader_path, const std::string &tex_path);
        Mesh2D(Shader mesh_shader, Texture2D mesh_texture);
        ~Mesh2D();
    };
}