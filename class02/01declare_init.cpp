#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0;
    int j;
    cout << i << endl; //输出0
    cout << j << endl; //编译不会出错，会输出16，这个值在不同的平台还不一样，所以必须init
    return 0;
}
