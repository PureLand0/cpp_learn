#include <iostream>
using namespace std;

union ipv4address
{
    uint32_t address32;
    uint8_t address8[4];
};

//union修饰之后 address32和address8其实指向的是同一块地址 只是不同的名称罢了 都是4B
//如果address32和address8 所代表的空间大小不一样 最终开辟的空间以大的为准 ！！！二者起始点是一样的
int main(int argc, char const *argv[])
{
    ipv4address demo;//declare
    demo.address32 = 0x12345678; //init
    //在内存中 地址从小到大这么存：78 56 34 12 这叫LSB 即 最低有效字节 存在 最低地址处
    cout <<hex <<  (int)demo.address8[0] <<endl;//78
    cout <<hex <<  (int)demo.address8[1] <<endl;//56
    cout <<hex <<  (int)demo.address8[2] <<endl;//34
    cout <<hex <<  (int)demo.address8[3] <<endl;//12
    return 0;
}
