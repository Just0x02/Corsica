#include <corsica/debugger.hpp>

#include <iostream>

using namespace Corsica;

void Debug::check_and_log_errors()
{
    const char *desc;
    i32 error_code = glfwGetError(&desc);

    if (error_code)
    {
        std::cerr << "[CORSICA][GLFW][ERROR] Error: '" << desc << "'" << std::endl; 
    }
}