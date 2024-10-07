#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char *name;
    int born;
    bool male;

public:
//每个对象都有一个this指针指向自己
//目标：调用成员函数的时候 传入this指针 用于区分到底是哪个对象调用的函数
    Student()
    {
        this->name = new char[1024]{0};
        this->born = 0;
        this->male = false;
        cout << "Constructor:1" << endl;
    }
    Student(const char *initName, int initBorn, bool isMale)
    {
        this->name = new char[1024];
        this->setName(initName);
        this->born = initBorn;
        this->male = isMale;
        cout << "Constructor: 2" << endl;
    }

    void setName(const char *s)
    {
        if (s == NULL)
        {
            std::cerr << "The input is NULL." << std::endl;
            return;
        }
        size_t len = 1024 - 1;
        strncpy(name, s, len);
        name[len] = '\0';
    }
};