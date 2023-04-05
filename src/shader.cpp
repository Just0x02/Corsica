#include <corsica/shader.hpp>
#include <corsica/fio.hpp>

#include <corsica/gfx.hpp>

#include <iostream>

using namespace Corsica;

Shader::Shader()
{

}

Shader::~Shader()
{
}

GLint Shader::compile(const char *shader_path, GLenum type)
{
    
    std::cout << "[CORSICA][SHADER][" << (type == GL_FRAGMENT_SHADER ? "FS" : "VS") << "] Compiling shader from path: '" << shader_path << "'" << std::endl;

    std::string shader_src = FileIO::read_file(shader_path);
    const char *shader_src_str = shader_src.c_str();

    i64 len = shader_src.size();

    GLuint handle = glCreateShader(type);
    glShaderSource(handle, 1, (const GLchar * const *) &shader_src_str, (const GLint *) &len);
    glCompileShader(handle);

    GLint compiled;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        std::cout << "Error occured when compiling shader: " << shader_path << std::endl;
        exit(-1);
    }

    return handle;
}

Shader Shader::create(const char *vertex_shader_path, const char *fragment_shader_path, std::vector<VertexAttr> attributes)
{
    Shader shader;

    shader.vs_handle = Shader::compile(vertex_shader_path, GL_VERTEX_SHADER);
    shader.fs_handle = Shader::compile(fragment_shader_path, GL_FRAGMENT_SHADER);
    shader.handle    = glCreateProgram();

    glAttachShader(shader.handle, shader.vs_handle);
    glAttachShader(shader.handle, shader.fs_handle);
    
    for (size_t i = 0; i < attributes.size(); i++)
    {
        glBindAttribLocation(shader.handle, attributes[i].index, attributes[i].name);
    }

    glLinkProgram(shader.handle);

    GLint linked;
    glGetProgramiv(shader.handle, GL_LINK_STATUS, &linked);

    if (!linked)
    {
        std::cout << "Error linking shader program..." << std::endl;
        exit(-1);
    }

    std::cout << "[CORSICA][SHADER] Created shader with PID:" << shader.handle << ", FSID:" << shader.fs_handle << ", VSID:" << shader.vs_handle << std::endl;

    return shader;
}

void Shader::destroy(const Shader &shader)
{
    
    std::cout << "[CORSICA][SHADER] Destroying shader ID:" << shader.handle << std::endl;
    glDeleteProgram(shader.handle);
    glDeleteShader(shader.vs_handle);
    glDeleteShader(shader.fs_handle);
}

void Shader::use(const Shader &shader)
{
    // std::cout << "[CORSICA][SHADER] Binding shader ID:" << shader.handle << std::endl;
    glUseProgram(shader.handle);
}

void Shader::unbind()
{
    glUseProgram(0);
}

void Shader::uniform_vec2(char *name, Vec2 vec)
{
    glUniform2f(glGetUniformLocation(this->handle, name), (f32) vec.x, (f32) vec.y);
}