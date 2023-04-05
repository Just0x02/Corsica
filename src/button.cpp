#include <corsica/button.hpp>
#include <corsica/window.hpp>

using namespace Corsica;

u64 Button::ticks_since_pressed()
{
    u64 current_tick = Window::get_instance().get_ticks();

    return current_tick - this->pressed_tick;
}

u64 Button::ticks_since_released()
{
    u64 current_tick = Window::get_instance().get_ticks();

    return current_tick - this->released_tick;
}
