#pragma once
#include "Object.h"
#include "Exceptions.h"

namespace CBGE 
{

class Event
{
public:
    Event() = default;
    Event(uint64_t senderId, uint32_t type);
    virtual ~Event() = default;

    uint64_t GetSender();
    uint64_t GetType();

    template <class EventType>
    EventType* Cast()
    {
        if (Type != EventType::EventId)
        {
            throw CastEventError(EventType::EventId, Type);
        }
        return dynamic_cast<EventType*>(this);
    }

private:
    uint64_t Sender;
    uint32_t Type;
};

}