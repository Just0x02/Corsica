#pragma once

#include <corsica/gfx.hpp>

#include <corsica/mat4.hpp>
#include <corsica/vec2.hpp>
#include <corsica/vec3.hpp>
#include <corsica/vec4.hpp>

#include <string>
#include <vector>

namespace Corsica
{
    struct VertexAttr
    {
        GLuint index;
        const GLchar *name;
    };

    struct Shader
    {
        GLuint handle, vs_handle, fs_handle;

        Shader();
        ~Shader();

        static GLint compile(const char *shader_path, GLenum type);
        static Shader create(const char *vertex_shader_path, const char *fragment_shader_path, std::vector<VertexAttr> attributes);
        static void destroy(const Shader &shader);
        static void use(const Shader &shader);
        static void unbind();

        void uniform_mat4(char *name, Mat4 mat);
        void uniform_vec2(char *name, Vec2 vec);
        void uniform_vec3(char *name, Vec3 vec);
        void uniform_vec4(char *name, Vec4 vec);
        void uniform_float(char *name, f32 flt);
        void uniform_int(char *name, i32 i);
        void uniform_uint(char *name, u32 u);
    };
};