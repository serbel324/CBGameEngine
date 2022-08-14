#pragma once

#include <stdexcept>

namespace CBGE
{

class CastEventError : public std::exception 
{
public:
    CastEventError(uint32_t expected, uint32_t actual)
        : ExpectedId(expected)
        , ActualId(actual)
    {
    }

    const char* what() 
    {
        return "Cast event error";
    }

private:
    const uint32_t ExpectedId;
    const uint32_t ActualId;
};

}