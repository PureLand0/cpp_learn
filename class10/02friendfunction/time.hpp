#pragma once
#include <iostream>

using namespace std;

class MyTime
{
    int hours;
    int minutes;

public:
    MyTime() : hours(0), minutes(0) {}
    MyTime(int h, int m) : hours(h), minutes(m) {}

    MyTime operator+(const MyTime &t) const
    {
        MyTime sum;
        sum.minutes = this->minutes + t.minutes;
        sum.hours = this->hours + t.hours;

        sum.hours += sum.minutes / 60;
        sum.minutes %= 60;

        return sum;
    }
    MyTime &operator+=(const MyTime &t)
    {
        this->minutes += t.minutes;
        this->hours += t.hours;

        this->hours += this->minutes / 60;
        this->minutes %= 60;

        return *this;
    }

    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours += sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }

    std::string getTime() const
    {
        return std::to_string(this->hours) + " hours and " + std::to_string(this->minutes) + " minutes.";
    }

    // 朋友函数的特点是写在类里面 但是不属于成员方法

    // 朋友函数1
    // 目的：我们之前的定义只能用来time+int  不能反过来int+time  朋友函数可以帮我们解决这个问题
    friend MyTime operator+(int m, const MyTime &t)
    {
        return t + m;
    }

    // 朋友函数2
    // 重载<<
    // 返回值一定要是ostream
    friend std::ostream &operator<<(std::ostream &os, const MyTime &t)
    {
        std::string str = std::to_string(t.hours) + " hours and " + std::to_string(t.minutes) + " minutes.";
        os << str;
        return os;
    }

    // 朋友函数3
    // 重载>>
    // 返回值一定要是istream
    friend std::istream &operator>>(std::istream &is, MyTime &t)
    {
        is >> t.hours >> t.minutes;
        t.hours += t.minutes / 60;
        t.minutes %= 60;
        return is;
    }
};