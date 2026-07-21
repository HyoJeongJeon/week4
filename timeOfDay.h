#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "timeException.h"

namespace Jeonhyojeong2593270
{
    class timeOfDay
    {
    protected:
        int hour;
        int minute;

        void testHour()
        {
            if (hour < 0 || hour > 23)
            {
                throw timeException{"Invalid hour\n"};    //std::exit함수를 호출하는 부분을 예외클래스에 메시지를 넣어 던지게 변경
            }
        }

        void testMinute()
        {
            if (minute < 0 || minute > 59)
            {
                throw timeException{"Invalid minute\n"};
            }
        }

    public:
        timeOfDay(int h = 0, int m = 0) : hour{h}, minute{m}
        {
            testHour();
            testMinute();
        }

        virtual void input(std::istream& is = std::cin)
        {
            std::cout << "Enter hour: "; is >> hour; testHour();
            std::cout << "Enter minute: "; is >> minute; testMinute();
        }
        friend std::istream& operator>>(std::istream& is, timeOfDay& t)
        {
            t.input(is);
            return is;
        }
        
        void setHour(int h)
        {
            hour = h;
            testHour();
        }

        void setMinute(int m)
        {
            minute = m;
            testMinute();
        }

        virtual void print(std::ostream& os = std::cout) const
        {
            os << std::setw(2) << std::setfill('0') << hour << ":";
            os << std::setw(2) << std::setfill('0') << minute;
        }
        virtual ~timeOfDay(){}
        
        friend std::ostream& operator<<(std::ostream& os, const timeOfDay& t)
        {
            t.print(os);
            return os;
        }

        int getHour() const { return hour; }
        int getMinute() const { return minute; }

        timeOfDay& operator++()
        {
            ++minute;
            if (minute == 60) {minute = 0; ++hour;}
            if (hour == 24) {hour = 0;}
            return *this;
        }

        timeOfDay operator++(int)
        {
            timeOfDay temp{*this};
            ++(*this);
            return temp;
        }

        timeOfDay& operator+=(int m)
        {
            minute += m;
            if (minute >= 60)
            {
                hour += minute / 60;
                minute %= 60;
            }
            if (hour >= 24)
            {
                hour %= 24;
            }
            return *this;
        }

        friend std::istream& operator>>(std::istream& is, timeOfDay& t)
        {
            std::cout << "Enter hour: ";
            is >> t.hour; t.testHour();

            std::cout << "Enter minute: ";
            is >> t.minute; t.testMinute();

            return is;
        }

        friend bool operator==(const timeOfDay& t1, const timeOfDay& t2)
        {
            return t1.hour == t2.hour && t1.minute == t2.minute;
        }

        friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2)
        {
            int minute1{t1.hour * 60 + t1.minute};
            int minute2{t2.hour * 60 + t2.minute};
            int totalMinutes{minute1 + minute2};
            int newHour{totalMinutes / 60};
            int newMinute{totalMinutes % 60};
            if (newHour > 23)
            {
                newHour %= 24;
            }
            return timeOfDay{newHour, newMinute};
        }
    };
}