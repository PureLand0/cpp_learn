#include <iostream>
#include "mystring.hpp"

using namespace std;


int main()
{
    {
        MyString str1(10, "Shenzhen");//调用构造函数 申请10B内存
        cout << "str1: " << str1 << endl;

        MyString str2 = str1;//还是调用构造函数 str2的characters指针指向的str1的10B内存
        cout << "str2: " << str2 << endl;

        MyString str3;//调用构造函数 申请64B内存
        cout << "str3: " << str3 << endl;
        str3 = str1;//值copy str3的characters指针指向的str1的10B内存  这样64B的内存就泄露了
        cout << "str3: " << str3 << endl;
    }
    //而且这里会释放内存 那么这段内存将会被重复释放 报错
    cout << "end of main()" << endl; 
    return 0;
}