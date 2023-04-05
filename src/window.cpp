#include <corsica/window.hpp>
#include <corsica/time.hpp>
#include <corsica/event_manager.hpp>

#include <iostream>

using namespace Corsica;

Window::Window() : logger(Corsica::LogFlag::CORSICA | Corsica::LogFlag::)
{
    EventManager::get_instance()
        .register_event("window_init")
        .register_event("window_update")
        .register_event("window_tick")
        .register_event("window_render")
        .register_event("window_destroy")
        .register_event("window_resize")
        .register_event("window_error")
        .register_event("window_mouse_move")
        .register_event("window_mouse_button")
        .register_event("window_keyboard");

    this->logger.set_log_flags(LogFlag::CORSICA | LogFlag::WINDOW);
}


Window::~Window()
{

}

Window &Window::get_instance()
{
    static Window instance;
    return instance;
}

GLFWwindow* Window::get_handle() const
{
    return this->handle;
}

Window &Window::attach_window_handle(GLFWwindow *handle)
{
    this->handle = handle;
    return *this;
}

Vec2 Window::get_size() const
{
    i32 w, h;
    glfwGetFramebufferSize(this->handle, &w, &h);
    return Vec2(w, h);
}

const Mouse& Window::get_mouse()
{
    return this->mouse;
}

const Keyboard& Window::get_keyboard()
{
    return this->keyboard;
}

u64 Window::get_last_second() const
{
    return this->last_second;
}

u64 Window::get_frames() const
{
    return this->frames;
}

u64 Window::get_fps() const
{
    return this->fps;
}

u64 Window::get_last_frame() const
{
    return this->last_frame;
}

u64 Window::get_frame_delta() const
{
    return this->frame_delta;
}

u64 Window::get_ticks() const
{
    return this->ticks;
}

u64 Window::get_tps() const
{
    return this->tps;
}

u64 Window::get_tick_remainder() const
{
    return this->tick_remainder;
}

Logger &Window::get_logger()
{
    return Window::get_instance().logger;
}

Window &Window::set_size(const Vec2 &size)
{
    glfwSetWindowSize(this->handle, size.x, size.y);
    return *this;
}


Window &Window::set_size(u32 width, u32 height)
{
    glfwSetWindowSize(this->handle, width, height);
    return *this;
}

Window &Window::set_height(u32 height)
{
    Vec2 original = this->get_size();
    return this->set_size(original.x, height);
}

Window &Window::set_width(u32 width)
{
    Vec2 original = this->get_size();
    return this->set_size(width, original.y);
}

void Window::error(i32 code, const char *desc)
{
    std::cerr << "[GLFW][ERROR][" << code << "] " << desc << "." << std::endl;
}

void Window::resize(GLFWwindow *handle, i32 width, i32 height)
{
    glViewport(0, 0, width, height);

    EventManager::get_instance()
        .dispatch("window_resize");
}

void Window::cursor_change(GLFWwindow *handle, f64 xp, f64 yp)
{
    Window &instance = Window::get_instance();

    Vec2 new_pos = Vec2(xp, yp);

    instance.mouse.delta   = new_pos.sub(instance.mouse.position);
    instance.mouse.delta.clamp_xy(-100.0, 100.0);

    instance.mouse.position = new_pos;

    EventManager::get_instance()
        .dispatch("window_mouse_move");
}

void Window::key_change(GLFWwindow *handle, i32 key, i32 scancode, i32 action, i32 mods)
{
    if (key < 0) return;

    switch (action)
    {
        case GLFW_PRESS:
        {
            Window::get_instance().keyboard.keys[key].down = true;
            Window::get_instance().keyboard.keys[key].pressed_tick = Window::get_instance().get_ticks();
        } break;

        case GLFW_RELEASE:
        {
            Window::get_instance().keyboard.keys[key].down = false;
            Window::get_instance().keyboard.keys[key].released_tick = Window::get_instance().get_ticks();
        } break;

        default: break;
    }

    EventManager::get_instance()
        .dispatch("window_keyboard");
}

void Window::mouse_button_change(GLFWwindow *handle, i32 button, i32 action, i32 mods)
{
    if (button < 0) return;

    switch (action)
    {
        case GLFW_PRESS:
        {
            Window::get_instance().mouse.buttons[button].down = true;
            Window::get_instance().mouse.buttons[button].pressed_tick = Window::get_instance().get_ticks();
        } break;

        case GLFW_RELEASE:
        {
            Window::get_instance().mouse.buttons[button].down = false;
            Window::get_instance().mouse.buttons[button].released_tick = Window::get_instance().get_ticks();
        } break;

        default: break;
    }

    EventManager::get_instance()
        .dispatch("window_mouse_button");
}

void Window::destroy()
{
    EventManager::get_instance()
        .dispatch("window_destroy");

    glfwTerminate();
}

void Window::tick()
{
    Window::get_instance().ticks++;
}

void Window::init()
{
    Window &instance = Window::get_instance();

    instance.last_frame = Time::get_now_ns();
    instance.last_second = Time::get_now_ns();

    glfwSetErrorCallback(Window::error);

    if (!glfwInit())
    {
        std::cerr << "Error initializing GLFW" << std::endl;
        exit(1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    instance.attach_window_handle(
        glfwCreateWindow(300, 300, "Testing", NULL, NULL)
    );

    if (instance.get_handle() == NULL)
    {
        std::cerr << "Error when creating window..." << std::endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(instance.get_handle());

    glfwSetFramebufferSizeCallback(instance.get_handle(), Window::resize);
    glfwSetCursorPosCallback(instance.get_handle(), Window::cursor_change);
    glfwSetKeyCallback(instance.get_handle(), Window::key_change);
    glfwSetMouseButtonCallback(instance.get_handle(), Window::mouse_button_change);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        Window::get_logger().fatal("Error initializing GLAD.");
        glfwTerminate();
        exit(1);
    }

    // glfwSwapInterval(1);

    EventManager::get_instance()
        .dispatch("window_init");
}