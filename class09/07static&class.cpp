#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    // static修饰成员变量 那么这个成员变量被所有对象共享 且不依赖对象的初始化 即没有对象被初始化也可以使用  Student::student_total
    static size_t student_total; // 这里只declare 没有init
    // inline static size_t student_total = 0; //C++17, definition outside isn't needed
    char *name;
    int born;
    bool male;

public:
    Student()
    {
        student_total++;
        name = new char[1024]{0};
        born = 0;
        male = false;
        cout << "Constructor: Person(): student_total = " << student_total << endl;
    }
    Student(const char *initName, int initBorn, bool isMale)
    {
        student_total++;
        name = new char[1024];
        setName(initName);
        born = initBorn;
        male = isMale;
        cout << "Constructor: Person(const char, int , bool): student_total = " << student_total << endl;
    }
    ~Student()
    {
        student_total--;
        cout << "To destroy object: " << name;
        cout << ". Then " << student_total << " students are left" << endl;
        delete[] name;
    }

    void setName(const char *s)
    {
        if (s == NULL)
        {
            std::cout << "The input is NULL." << std::endl;
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
            std::cout << "The input b is " << b << ", and should be in [1990, 2020]." << std::endl;
    }
    // static修饰成员方法 则该方法可以在没有对象被实例化的情况下使用 Student::getTotal() 且该方法中不可以使用任何非static成员变量
    // 原因很简单 因为当调用getTotal()的时候可能压根没对象 那么哪来的非static的成员变量呢？ 以绝后患 
    static size_t getTotal()
    {
        return student_total;
    }

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

// init 这一步必须做 不然err
size_t Student::student_total = 0;

int main()
{
    // 这里的用法就是直接使用class来找到
    cout << "---We have " << Student::getTotal() << " students---" << endl;

    Student *class1 = new Student[3]{
        {"Tom", 2000, true},
        {"Bob", 2001, true},
        {"Amy", 2002, false},
    };

    cout << "---We have " << Student::getTotal() << " students---" << endl;

    Student yu("Yu", 2000, true);

    cout << "---We have " << yu.getTotal() << " students---" << endl;

    delete[] class1;

    cout << "---We have " << Student::getTotal() << " students---" << endl;

    return 0;
}