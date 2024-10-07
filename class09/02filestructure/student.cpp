#include "student.hpp"
#include <iostream>

using namespace std;

void Student::setGender(bool isMale)//注意函数名字前面加上Student::
{
    male = isMale;
}
void Student::printInfo()
{
    cout << "Name: " << name << endl;
    cout << "Born in " << born << endl;
    cout << "Gender: " << (male ? "Male" : "Female") << endl;
}