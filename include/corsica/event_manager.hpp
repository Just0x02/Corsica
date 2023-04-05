#pragma once

#include <types.h>

#include <corsica/event_context.hpp>
#include <corsica/event_callback.hpp>

#include <functional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Corsica
{
    class EventManager
    {
        public:
            static EventManager &get_instance();

            EventManager();
            ~EventManager();
            // EventManager(EventManager const&);
            // void operator=(EventManager const&);

            EventManager &register_event(const std::string &event_id);

            EventManager &subscribe_to(const std::string &event_id, std::function<void(EventContext&)> cb);
            EventManager &subscribe_to(const std::string &event_id, EventCallback cb);

            EventManager &dispatch(const std::string &event_id);
            EventManager &dispatch(const std::string &event_id, EventContext context);

            bool has_event(const std::string &event_id);

            EventManager &clean_disabled_handlers();

        private:

            std::unordered_map<std::string, std::vector<EventCallback>> event_handlers;
    };
};