#include "Object.h"

Object::Object(uint64_t id)
    : Id(id)
{
}

uint64_t Object::GetId()
{
    return Id;
}
