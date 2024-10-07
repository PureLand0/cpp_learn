//hello.cpp 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "!"};
    
    for (const string& word : msg) //C++11 standard
    {
        cout << word << " ";
    }
    cout << endl;
}

//编译
//g++ compile.cpp 进行编译 生成a.exe可执行文件
//g++ compile.cpp --std=c++11 使用c++11标准进行编译 因为现在的标准是c++8 生成a.exe可执行文件
//g++ compile.cpp --std=c++11 -o compile  改名生成compile.exe可执行文件

//运行
//  ./compile.exe 或者./compile都可