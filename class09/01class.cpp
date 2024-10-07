#include <iostream>
#include <cstring>

// 其实struct和class是差不多的 只不过struct只能定义成员变量 但是class既可以定义成员变量 也可以定义成员函数
class Student
{
    // 被private修饰之后，只在class类内可以被访问
    // 如果啥都不写 则默认就是private
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

    void setGender(bool isMale)
    {
        male = isMale;
    }
    void printInfo()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Born in " << born << std::endl;
        std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
    }
};

int main()
{
    Student yu;
    yu.setName("Yu");
    yu.setBorn(2000);
    yu.setGender(true);

    // yu.born = 2001; // you cannot access a private member
    yu.printInfo();
    return 0;
}