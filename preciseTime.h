#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "timeOfDay.h"

namespace Jeonhyojeong2593270
{
    class preciseTime : public timeOfDay
    {
    private:
        int second;

        void testSecond()
        {
            if (second < 0 || second > 59)
            {
                std::cout << "invalid second\n";
                std::exit(1);
            }
        }

    public:
        preciseTime(int h = 0, int m = 0, int s = 0)
            : timeOfDay{h, m}, second{s}
        {
            testSecond();
        }

        int getSecond() const { return second; }
        
        void setSecond(int s) 
        { 
            second = s; 
            testSecond(); 
        }

        virtual void print(std::ostream& os = std::cout) const
        {
            timeOfDay::print(os);
            os << ':' << std::setfill('0') << std::setw(2) << second;
        }

        friend std::ostream& operator<<(std::ostream& os, const preciseTime& p)
        {
            os << static_cast<const timeOfDay&>(p) << ':';
            os << std::setfill('0') << std::setw(2) << p.second;
            return os;
        }
    };
}
