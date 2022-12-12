#pragma once
#include <iostream>
#include "DebugMsg.h"
namespace Commons
{
    class NotImplementedException : public std::exception
    {
    public:
        virtual char const* what() const 
        { 
            return "Function not yet implemented!"; 
        }
    };
}

