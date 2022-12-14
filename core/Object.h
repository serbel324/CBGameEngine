#pragma once
#include <cstdint>

namespace CBGE
{

class Object
{
public:
    Object() = default;
    Object(uint64_t id);
    virtual ~Object() = default;

    uint64_t GetId();

private:
    uint64_t Id;
};

}