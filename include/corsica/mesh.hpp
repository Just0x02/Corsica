#pragma once

#include <types.h>

#include <corsica/shader.hpp>
#include <corsica/texture.hpp>

#include <corsica/vao.hpp>
#include <corsica/vbo.hpp>
#include <corsica/ebo.hpp>

#include <corsica/vertex.hpp>
#include <corsica/meshdata.hpp>

#include <corsica/gfx.hpp>

#include <vector>
#include <string>

namespace Corsica
{
    struct MeshConfig
    {
        bool use_wireframe;
    };

    struct Mesh
    {
        Shader mesh_shader;
        Texture2D mesh_texture;

        VAO vao;
        VBO vbo;
        EBO ebo;

        MeshData mesh_data;
        MeshConfig config;

        virtual MeshData &compile_mesh() = 0;
        virtual void destroy_mesh();
        void draw_mesh();
        void use_config(MeshConfig config);

        Mesh();
        Mesh(const std::string &vs_shader_path, const std::string &fs_shader_path, std::vector<VertexAttr> attributes, const std::string &tex_path);
        Mesh(Shader mesh_shader, Texture2D mesh_texture);
        virtual ~Mesh();
    };
};