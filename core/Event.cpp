#include "Event.h"

namespace CBGE
{

Event::Event(uint64_t senderId, uint32_t type)
    : Sender(senderId)
    , Type(type)
{
}

uint64_t Event::GetSender()
{
    return Sender;
}

uint64_t Event::GetType()
{
    return Type;
}

}