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
    Student students[128];
    Student *p0 = &students[0];
    Student *p1 = &students[1];
    Student *p2 = &students[2];
    Student *p3 = &students[3];

    // 下面的动作是一样的
    students[1].born = 2000;
    p1->born = 2000;

    // 下面三个所代表的是一样的
    printf("&students = %p\n", &students);
    printf("students = %p\n", students);//数字名字其实就是地址
    printf("&students[0] = %p\n", &students[0]);

    //
    Student *p = students;
    p[0].born = 2000; // p[0] 相当于 *(p+0)！！！
    p[1].born = 2001;
    p[2].born = 2002;

    // arithmetic.cpp
    int numbers[4] = {0, 1, 2, 3};
    int *p11 = numbers + 1; // point to the element with value 1
    p11++;                  // point to the element with value 2
    *p11 = 20;              // change number[2] from 2 to 20
    *(p11 - 1) = 10;        // change number[1] from 1 to 10
    p11[1] = 30;            // change number[3] from 3 to 30


    // bound.cpp
    int num = 0;
    int *p22 = &num;
    p22[-1] = 2;    // 不报错 但是溢出了
    p22[0] = 3;     // okay
    *(p22 + 1) = 4; // 不报错 但是溢出了

    return 0;
}
