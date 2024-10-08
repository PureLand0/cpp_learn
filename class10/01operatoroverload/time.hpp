#pragma once
#include <iostream>
using namespace std;

// 运算符重载 比如我现在定义了一个MyTime类 我希望当我这么写的时候MyTime1+MyTime2
// 程序能自动识别出来我的目的是想让这两个时间相加 这个就叫“运算符重载”
class MyTime
{
    int hours;
    int minutes;

public:
    MyTime() : hours(0), minutes(0)
    {
    }
    MyTime(int h, int m) : hours(h), minutes(m)
    {
    }

    //+
    MyTime operator+(const MyTime &t) const
    {
        MyTime sum;
        sum.minutes = this->minutes + t.minutes;
        sum.hours = this->hours + t.hours;

        sum.hours += sum.minutes / 60;
        sum.minutes %= 60;

        return sum;
    }

    //+= 避免copy操作
    MyTime & operator+=(const MyTime &t)
    {
        this->minutes += t.minutes;
        this->hours += t.hours;

        this->hours += this->minutes / 60;
        this->minutes %= 60;

        return *this;
    }

    //打印
    string getTime() const
    {
        return to_string(this->hours) + " hours and " + to_string(this->minutes) + " minutes.";
    }

    
    //对+整数的overload
    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours += sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }


    //对+=整数的overload
    MyTime &operator+=(int m)
    {
        this->minutes += m;
        this->hours += this->minutes / 60;
        this->minutes %= 60;
        return *this;
    }

    //对+字符串的overload
    MyTime operator+(const string str) const
    {
        MyTime sum = *this;//复制
        if (str == "one hour")
            sum.hours = this->hours + 1;
        else
            cout << "Only \"one hour\" is supported." << endl;
        return sum;
    }
};