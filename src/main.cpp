#include <types.h>

#include <corsica/gfx.hpp>
#include <corsica/vbo.hpp>
#include <corsica/vao.hpp>
#include <corsica/shader.hpp>
#include <corsica/event_manager.hpp>
#include <corsica/window.hpp>
#include <corsica/mesh2d.hpp>
#include <corsica/mesh3d.hpp>
#include <corsica/debugger.hpp>
#include <corsica/mouse_button_event.hpp>

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
        })
        .subscribe_to("window_mouse_button", [](Corsica::EventContext &ctx) {
            Corsica::MouseButtonEvent *event = (Corsica::MouseButtonEvent *) ctx.raw_data;
            Corsica::Window::get_logger().info("Mouse button pressed args => ", event->button, ", ", event->action, ", ", event->mods);

            if (event->button == GLFW_MOUSE_BUTTON_1 && event->action == GLFW_PRESS)
            {
                Corsica::Window &instance = Corsica::Window::get_instance();

                Corsica::Window::get_logger().debug("Window State Data:");
                Corsica::Window::get_logger().debug("TICKS: ", instance.get_ticks());
                Corsica::Window::get_logger().debug("FRAMES: ", instance.get_frames());
                Corsica::Window::get_logger().debug("TIME START: ", instance.get_start_time());
                Corsica::Window::get_logger().debug("TIME SINCE START: ", instance.get_time_since_start());
            }
        });
        // .subscribe_to("window_tick", [](Corsica::EventContext &ctx) {
        //     Corsica::Window::get_logger().info("TIME SINCE START: ", ((f64) Corsica::Window::get_instance().get_time_since_start()) / 1000000000.0);
        // });
        // .subscribe_to("window_mouse_move", [](Corsica::EventContext &ctx) {
        //     Corsica::Mouse mouse = Corsica::Window::get_instance().get_mouse();

        //     std::cout << "Mouse pos: " << mouse.position.as_string() << ", Delta: " << mouse.delta.as_string() << std::endl;
        // });
    Corsica::Window &instance = Corsica::Window::get_instance();
    instance.init();

    Corsica::Mesh2D test_mesh = Corsica::Mesh2D(
        "./res/shaders/basic_texture.vs", 
        "./res/shaders/basic_texture.fs",
        {
            { .index = 0, .name = "res"  },
            { .index = 1, .name = "tick" },
            { .index = 2, .name = "time" }
        },
        "./res/images/default.png"
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
