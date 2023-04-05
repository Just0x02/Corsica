#include <types.h>

#include <corsica/gfx.hpp>
#include <corsica/vbo.hpp>
#include <corsica/vao.hpp>
#include <corsica/shader.hpp>
#include <corsica/event_manager.hpp>
#include <corsica/window.hpp>
#include <corsica/mesh2d.hpp>
#include <corsica/debugger.hpp>

#include <iostream>


// void error_callback(int error, const char* description)
// {
//     fprintf(stderr, "Error: %s\n", description);
// }

// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }  

// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// void displayMe(void)
// {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glBegin(GL_POLYGON);
//         glVertex3f(0.5, 0.0, 0.5);
//         glVertex3f(0.5, 0.0, 0.0);
//         glVertex3f(0.0, 0.5, 0.0);
//         glVertex3f(0.0, 0.0, 0.5);
//     glEnd();
//     glFlush();
// }

int main(int argc, char** argv)
{   
    Corsica::EventManager::get_instance()
        .subscribe_to("window_init", [](Corsica::EventContext &ctx) {
            Corsica::Window::get_logger().info("Window has init'd");
            // std::cout << "Window has init'd" << std::endl;
        });
        // .subscribe_to("window_mouse_move", [](Corsica::EventContext &ctx) {
        //     Corsica::Mouse mouse = Corsica::Window::get_instance().get_mouse();

        //     std::cout << "Mouse pos: " << mouse.position.as_string() << ", Delta: " << mouse.delta.as_string() << std::endl;
        // });


    Corsica::Window &instance = Corsica::Window::get_instance();

    instance.init();

    Corsica::Mesh2D test_mesh = Corsica::Mesh2D(
        Corsica::Shader::create(
            "./res/shaders/simple_shader.vs", 
            "./res/shaders/simple_shader.fs",
            {
                // { .index = 0, .name = "res" }
            }
        ),
        Corsica::Texture2D()
    );

    test_mesh.compile_mesh();


    while (!glfwWindowShouldClose(instance.get_handle()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Corsica::Window::tick();

        test_mesh.draw_mesh();

        glfwSwapBuffers(instance.get_handle());
        glfwPollEvents();
    }

    return 0;
}