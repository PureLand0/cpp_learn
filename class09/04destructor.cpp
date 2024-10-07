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
    Student()
    {
        name = new char[1024]{0};
        born = 0;
        male = false;
        cout << "Constructor:1" << endl;
    }
    Student(const char *initName, int initBorn, bool isMale)
    {
        name = new char[1024];
        setName(initName);
        born = initBorn;
        male = isMale;
        cout << "Constructor: 2" << endl;
    }

    // 这个就是析构函数 只能有一个
    // 如果自己不定义 默认有一个
    ~Student()
    {
        cout << "To destroy object: " << name << endl;
        delete[] name;
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
    void setBorn(int b)
    {
        if (b >= 1990 && b <= 2020)
            born = b;
        else
            std::cerr << "The input b is " << b << ", and should be in [1990, 2020]." << std::endl;
    }
    // the declarations, the definitions are out of the class
    void setGender(bool isMale);
    void printInfo();
};

void Student::setGender(bool isMale)
{
    male = isMale;
}
void Student::printInfo()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Born in " << born << std::endl;
    std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
}

int main()
{

    Student yu;
    yu.printInfo();

    Student xue = Student("XueQikun", 1962, true);
    xue.printInfo();

    Student *zhou = new Student("Zhou", 1991, false);
    zhou->printInfo();
    delete zhou;//主动调用析构函数 如果不写这一行代码 那么zhou的析构函数不会被调用


    //在函数结束之前 yu和xue才会调用析构函数

    return 0;
}