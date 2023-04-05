#include <corsica/mouse.hpp>
#include <corsica/gfx.hpp>
#include <corsica/window.hpp>

using namespace Corsica;

void Mouse::set_grabbed(bool grabbed)
{
    glfwSetInputMode(
        Window::get_instance().get_handle(), 
        GLFW_CURSOR, 
        grabbed ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL
    );
}

bool Mouse::is_grabbed()
{
    return glfwGetInputMode(Window::get_instance().get_handle(), GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
}
