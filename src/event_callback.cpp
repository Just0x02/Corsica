#include <corsica/event_callback.hpp>

using namespace Corsica;

EventCallback::EventCallback(std::function<void(EventContext&)> cb) : cb(cb)
{
    this->enabled = true;
}