#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char name[4];
    int born;
    bool male;

public:
    //注意：构造函数的名称必须和class名称保持一致
    //如果自己不定义构造函数 系统将会有一个默认的构造函数 类似于java
    //构造函数1
    Student()
    {
        name[0] = 0;
        born = 0;
        male = false;
        cout << "Constructor: 1" << endl;
    }
    //构造函数2
    Student(const char *initName) : born(0), male(false)
    {
        setName(initName);
        cout << "Constructor: 2" << endl;
    }
    //构造函数3
    Student(const char *initName, int initBorn, bool isMale)
    {
        setName(initName);
        born = initBorn;
        male = isMale;
        cout << "Constructor: 3" << endl;
    }

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
    // the declarations, the definitions are out of the class
    void setGender(bool isMale);
    void printInfo();
};
//2个成员函数写出来
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
//注意：类的创建和结构体的创建不一样 结构体的创建eg：student s={}，在new结构体的时候也就class05的那2种 常常使用{}
//但是类的创建因为要调用构造器 所以常常用()
{
    Student yu;//调用的初始化函数1 等价于  Student yu = Student()
    yu.printInfo();

    Student li("li");//调用的初始化函数2 等价于  Student li = Student("li")
    li.printInfo();

    Student xue = Student("Xn", 1962, true);//调用的初始化函数3 等价于  Student xue = Student("Xn", 1962, true)
    xue.printInfo();

    Student *zhou = new Student("Zhou", 1991, false);//调用的初始化函数3
    zhou->printInfo();
    delete zhou;

    Student *s = new Student();//调用的初始化函数1 
    s->printInfo();
    delete s;

    //class对象的初始化有2种 一种有new 一种没有 没有new的将会在栈上创建 且函数块运行结束之前自动销毁（析构函数）
    //但是new的会在堆上创建 需要手动delete销毁（析构函数）

    return 0;
}