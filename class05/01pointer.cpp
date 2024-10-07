#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // 指针里面存的是地址 一般8B 64位系统的地址就是64b的 每个地址和字节一一对应
    int num = 10;
    int *p1 = NULL, *p2 = NULL;
    p1 = &num;
    p2 = &num;
    *p1 = 20; //*p可以取到指针p所指向的内容
    *p2 = 30;

    // 指针也可以指向结构体对象
    struct Student
    {
        char name[4];
        int born;
        bool male;
    };
    Student stu = {"Yu", 2000, true};
    Student *pStu = &stu;
    // pStu->name  与 (*pStu).name等效
    strncpy(pStu->name, "Li", 4);
    // 下面两个等效
    pStu->born = 2001;
    (*pStu).born = 2002;
    pStu->male = false;

    // 双指针
    int num = 10;
    int *p = &num;
    int **pp = &p;
    *(*pp) = 20;
    cout << "num = " << num << endl;

    // 如果在一个指针的前面加了const 那么就不能通过这个指针修改这个量了 只能通过别的方法来进行 但是p1本身还可以指向别人
    int num = 1;
    int another = 1;
    const int *p1 = &num;
    *p1 = 3;       // error
    num = 3;       // okay
    p1 = &another; // okay

    // 如果const只是在指针的指针名的前面 那么可以通过这个指针修改这个变量 但是指针本身不能再指向别人
    int *const p2 = &num;
    *p2 = 3;       // okay
    p2 = &another; // error

    return 0;
}
