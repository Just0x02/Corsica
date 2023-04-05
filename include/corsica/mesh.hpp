#pragma once

#include <types.h>

#include <corsica/shader.hpp>
#include <corsica/texture.hpp>

#include <corsica/vao.hpp>
#include <corsica/vbo.hpp>
#include <corsica/ebo.hpp>

#include <corsica/vertex.hpp>

#include <corsica/gfx.hpp>

#include <vector>
#include <string>

namespace Corsica
{
    struct MeshData
    {
        std::vector<f32> vertices;
        std::vector<f32> colors;
        std::vector<f32> tex_coords;

        u32 vertex_size;
    };

    struct Mesh
    {
        Shader mesh_shader;
        Texture2D mesh_texture;

        VAO vao;
        VBO vbo;
        EBO ebo;

        std::vector<u32> indices;
        MeshData mesh_data;

        virtual MeshData &compile_mesh() = 0;
        virtual void destroy_mesh();
        void draw_mesh();

        Mesh(const std::string &vs_shader_path, const std::string &fs_shader_path, const std::string &tex_path);
        Mesh(Shader mesh_shader, Texture2D mesh_texture);
        virtual ~Mesh();
    };
};