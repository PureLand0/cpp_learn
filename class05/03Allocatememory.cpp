#include <iostream>
using namespace std;

struct Student
{
    char name[4];
    int born;
    bool male;
};

int main(int argc, char const *argv[])
{
    //申请
    // 申请一段int类型的内存 将地址赋给p1 不初始化
    int *p1 = new int;
    // 申请一段int类型的内存 将地址赋给p2 初始化为0
    int *p2 = new int();
    // 申请一段int类型的内存 将地址赋给p3 初始化为5
    int *p3 = new int(5);
    // 申请一段int类型的内存 将地址赋给p4 初始化为0
    int *p4 = new int{}; // C++11
    // 申请一段int类型的内存 将地址赋给p5 初始化为5 推荐
    int *p5 = new int{5}; // C++11

    // 申请一段Student类型的内存 将地址赋给ps1 不初始化
    Student *ps1 = new Student;
    // 申请一段Student类型的内存 将地址赋给ps2 初始化 推荐
    Student *ps2 = new Student{"Yu", 2020, 1}; // C++11

    // allocate 16 int, 不初始化
    int *pa1 = new int[16];
    // allocate 16 int, 初始化为0
    int *pa2 = new int[16]();
    // allocate 16 int, 初始化为0
    int *pa3 = new int[16]{}; // C++11
    // allocate 16 int, 前三个初始化为1 2 3 后面全0 推荐
    int *pa4 = new int[16]{1, 2, 3}; // C++11

    // allocate memory for 16 Student objects, 不初始化
    Student *psa1 = new Student[16];
    // allocate memory for 16 Student objects, the first two are explicitly initialized 推荐
    Student *psa2 = new Student[16]{{"Li", 2000, 1}, {"Yu", 2001, 1}}; // C++11

    //释放
    // 如果指针指向的单个变量 比如基本类型或者结构体 可以使用下面这个
    delete p1;
    delete ps1;

    // 如果指针指向的数组类型 则推荐使用带[]的
    delete pa1;
    delete[] pa2;
    
    delete psa1;
    delete[] psa2;
}