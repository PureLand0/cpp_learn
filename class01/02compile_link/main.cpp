//main.cpp
#include <iostream>
#include "mul.hpp" //包含头文件；main需要用到mul函数

using namespace std;
int main()
{
    int a, b;
    int result;

    cout << "Pick two integers:";
    cin >> a;
    cin >> b;

    result = mul(a, b);

    cout << "The result is " << result << endl;
    return 0;
}
/**
 * 我们当然可以把mul和main写一块 但是当code很长时 就很不方便
 * 拆开的方法演示过了 就是使用头文件hpp 需要include
 * 使用g++ -c main.cpp将main.cpp编译为main.o这个object文件 其与.exe文件的区别在于没有进行link
 * 使用g++ -c mul.cpp将mul.cpp编译为mul.o这个object文件
 * 接下来进行link 使用命令 g++ main.o mul.o -o main 生成main.exe可执行文件
 * 运行命令
 * 
 * 从这里我们可以看出 g++ -c 只做编译，生成 .o 对象文件；而没有 -c 选项的 g++ 会做编译加链接，生成 .exe 可执行文件
 * 在大型项目中，通常先用 g++ -c 编译所有的源文件生成 .o 文件，然后一次性链接这些 .o 文件，这样可以提高构建效率，因为修改了某个源文件后，只需要重新编译那个文件，而不是整个项目。
 */