#pragma once

#include <types.h>

#include <corsica/gfx.hpp>
#include <corsica/vec2.hpp>

#include <corsica/button.hpp>
#include <corsica/keyboard.hpp>
#include <corsica/mouse.hpp>

#include <corsica/logger.hpp>

#include <vector>

namespace Corsica
{
    class Window
    {
        public:
            static Window& get_instance();

            Window(Window const&) = delete;
            void operator=(Window const&) = delete;

            GLFWwindow *get_handle() const;
            Vec2 get_size() const;

            const Mouse &get_mouse();
            const Keyboard &get_keyboard();

            u64 get_last_second() const;
            u64 get_frames() const;
            u64 get_fps() const;
            u64 get_last_frame() const;
            u64 get_frame_delta() const;
            u64 get_ticks() const;
            u64 get_tps() const;
            u64 get_tick_remainder() const;
            u64 get_start_time() const;
            u64 get_time_since_start() const;

            Window &set_size(const Vec2 &size);
            Window &set_size(u32 width, u32 height);
            Window &set_height(u32 height);
            Window &set_width(u32 width);

            Window &attach_window_handle(GLFWwindow *handle);

            static Logger &get_logger();
            static void init();
            static void render_loop();
            static void destroy();
            static void tick();
            static void update();
            static void render();
            static void resize(GLFWwindow *handle, i32 width, i32 height);
            static void error(i32 code, const char *desc);
            static void cursor_change(GLFWwindow *handle, f64 xp, f64 yp);
            static void key_change(GLFWwindow *handle, i32 key, i32 scancode, i32 action, i32 mods);
            static void mouse_button_change(GLFWwindow *handle, i32 button, i32 action, i32 mods);

        private:
            Window();
            ~Window();

            GLFWwindow *handle;

            Logger logger;
        
            Mouse mouse;
            Keyboard keyboard;
    
            u64 start_time;
            u64 last_second;
            u64 frames, fps, last_frame, frame_delta;
            u64 ticks, tps, tick_remainder;
    };
};