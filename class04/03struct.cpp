#include <iostream>
#include <string.h>
using namespace std;

struct Student
{
    char name[4];
    int born;
    bool male;
}; // 这个不可以丢掉

int main(int argc, char const *argv[])
{
    // declare
    Student stu;
    // init1
    strcpy(stu.name, "Yu");
    stu.born = 2000;
    stu.male = true;
    
    // declare and init2
    Student stu1 = {"Yu", 2000, true};

    //也可以指定传那个
    Student stu2 = {.born=2000, .male=true};
    

    // 数组形式
    Student students[100];
    students[50].born = 2002;

    return 0;
}

//padding
struct Student1
{
    int id;//占4B
    bool male;//占1B
    char label;//占1B
    float weight;//占4B 但是他不会接着label排列 而是padding2B 才是weight
    
    //故总共占了12B 内存是线性排列的  即每个Student1对象都会占据12B
};