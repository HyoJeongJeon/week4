#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "timeOfDay.h"
#include "timeException.h"

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
                throw timeException{"Invalid second"};
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


        // virtual void print(std::ostream& os = std::cout) const
        // {
        //     timeOfDay::print(os);
        //     os << ':' << std::setfill('0') << std::setw(2) << second;
        // }

        // friend std::ostream& operator<<(std::ostream& os, const preciseTime& p)
        // {
        //     p.print(os);
        //     return os;
        // }
        virtual void print(std::ostream& os = std::cout) const override
        {
            timeOfDay::print(os);
            os << ':' << std::setfill('0') << std::setw(2) << second << '\n';

        }
        virtual void input(std::istream& is = std::cin) override
        {
            timeOfDay::input(is);
            std::cout << "Enter second: "; is >> second; testSecond();
        }
    };
}
