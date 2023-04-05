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
    struct Mesh3D : Corsica::Mesh
    {
        static const u32 VERTEX_SIZE = 3;

        MeshData &compile_mesh();

        Mesh3D(const std::string &vs_shader_path, const std::string &fs_shader_path, const std::string &tex_path);
        Mesh3D(Shader mesh_shader, Texture2D mesh_texture);
        ~Mesh3D();
    };
}