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
#include <corsica/ecs/ecs.hpp>
#include <corsica/ecs/mesh_c.hpp>

#include <libnoise/noise.h>
#include <libnoise/noisegen.h>
#include <libnoise/module/perlin.h>

#include <iostream>

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

    Corsica::ECS::Entity test_entity;

    test_entity.add_component<Corsica::ECS::MeshComponent>(
        new Corsica::Mesh2D(
            "./res/shaders/basic_texture.vs", 
            "./res/shaders/basic_texture.fs",
            {
                { .index = 0, .name = "res"  },
                { .index = 1, .name = "tick" },
                { .index = 2, .name = "time" }
            },
            "./res/images/default.png"
        )
    );

    // Corsica::Mesh2D test_mesh = Corsica::Mesh2D(
    //     "./res/shaders/basic_texture.vs", 
    //     "./res/shaders/basic_texture.fs",
    //     {
    //         { .index = 0, .name = "res"  },
    //         { .index = 1, .name = "tick" },
    //         { .index = 2, .name = "time" }
    //     },
    //     "./res/images/default.png"
    // );

    // test_mesh.compile_mesh();

    // Corsica::Image noisy_img = Corsica::Image("./res/images/default.png");
    // noise::module::Perlin pn = noise::module::Perlin();
    // pn.SetSeed((u32) Corsica::Window::get_instance().get_time_since_start());
    // Corsica::PerlinNoise pn = Corsica::PerlinNoise();

    // for (u32 y = 0; y < noisy_img.height; y++)
    // {
    //     for (u32 x = 0; x < noisy_img.width; x++)
    //     {
    //         Corsica::RGBA rgba = Corsica::RGBA(255, 255, 255, 255);// Corsica::RGBA(noisy_img.pixels[y + noisy_img.width * x]);
            
    //         f64 noise = pn.GetValue(x / 10.0, y / 10.0, 1.0);

    //         rgba.r *= noise;
    //         rgba.g *= noise;
    //         rgba.b *= noise;

    //         // Corsica::Window::get_logger().debug("N: ", noise, " (", x, ", ", y, ")", " => ", rgba.as_string());

    //         noisy_img.pixels[y + noisy_img.width * x] = (u32) rgba;
    //     }
    // }

    // for (u32 pixel_idx = 0; pixel_idx < noisy_img.get_pixels_size(); pixel_idx += noisy_img.channels)
    // {
    //     u8 &r = noisy_img.pixels[pixel_idx + 0];
    //     u8 &g = noisy_img.pixels[pixel_idx + 1];
    //     u8 &b = noisy_img.pixels[pixel_idx + 2];
    //     u8 &a = noisy_img.pixels[pixel_idx + 3];

    //     r *= pn.noise(pixel_idx + 0, pixel_idx + 1, pixel_idx + 2);
    //     g *= pn.noise(pixel_idx + 1, pixel_idx + 2, pixel_idx + 0);
    //     b *= pn.noise(pixel_idx + 0, pixel_idx + 2, pixel_idx + 1);
    // }

    // noisy_img.write_to_file("./lol.png");


    while (!glfwWindowShouldClose(instance.get_handle()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Corsica::Window::tick();

        test_entity.get_component<Corsica::ECS::MeshComponent>().mesh->draw_mesh();
        // test_mesh.draw_mesh();

        glfwSwapBuffers(instance.get_handle());
        glfwPollEvents();
    }

    return 0;
}
