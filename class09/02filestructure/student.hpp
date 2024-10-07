#include <iostream>
#include <cstring>
#pragma once//只可以被include一次 不要重复被include

class Student
{
//被private修饰之后，只在class类内可以被访问
private:
    char name[4];
    int born;
    bool male;

public:
    void setName(const char *s)
    {
        if (s == NULL)
        {
            std::cerr << "The input is NULL." << std::endl;
            return;
        }
        size_t len = sizeof(name) - 1;
        strncpy(name, s, len);
        name[len] = '\0';
    }

    void setBorn(int b)
    {
        if (b >= 1990 && b <= 2020)
            born = b;
        else
            std::cerr << "The input b is " << b << ", and should be in [1990, 2020]." << std::endl;
    }

    //一些成员函数涉及到io等操作或者逻辑比较复杂 不建议写在class里面 可以写到外面或者再定义一个cpp文件
    //这里我们使用student.cpp为例
    //即student.hpp 和 student.cpp为一组
    void setGender(bool isMale);
    void printInfo();
   
};