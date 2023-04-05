#include <corsica/event_manager.hpp>

#include <algorithm>

using namespace Corsica;

EventManager::EventManager()
{
}

EventManager::~EventManager()
{

}

EventManager &EventManager::get_instance()
{
    static EventManager instance;
    return instance;
}

EventManager &EventManager::register_event(const std::string &event_id)
{
    if (!this->has_event(event_id)) 
        this->event_handlers[event_id] = {};
    return *this;
}

EventManager &EventManager::subscribe_to(const std::string &event_id, std::function<void(EventContext&)> cb)
{
    return this->subscribe_to(event_id, EventCallback(cb));
}

EventManager &EventManager::subscribe_to(const std::string &event_id, EventCallback cb)
{
    if (!this->has_event(event_id))
        this->register_event(event_id);
    
    this->event_handlers[event_id].push_back(
        cb
    );

    return *this;
}

EventManager &EventManager::dispatch(const std::string &event_id)
{
    return this->dispatch(event_id, (EventContext) {
        .event_id = event_id,
        .raw_data = nullptr,
        .allow_passthrough = true
    });
}

EventManager &EventManager::dispatch(const std::string &event_id, EventContext context)
{
    if (!this->has_event(event_id)) return *this;

    std::vector<EventCallback> &handlers = this->event_handlers[event_id];

    if (handlers.size() == 0) return *this;

    for (const auto &handler : handlers)
    {
        if (handler.enabled)
            handler.cb(context);
    }

    return *this;
}

EventManager &EventManager::clean_disabled_handlers()
{
    for (auto &event_pair : this->event_handlers)
    {
        event_pair.second.erase(
            std::remove_if(event_pair.second.begin(), event_pair.second.end(), [](EventCallback &cb) {
                return !cb.enabled;
            }), event_pair.second.end()
        );
    }

    return *this;
}


bool EventManager::has_event(const std::string &event_id)
{
    return this->event_handlers.find(event_id) != this->event_handlers.end();
}


// EventManager::EventManager(EventManager const&) = delete;
// void EventManager::operator=(EventManager const&) = delete;