#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int nums1[5]; // 只declare 没有init 虽然开辟了空间 但是里面全是随机值

    int nums2[5] = {0, 1, 2, 3, 4}; // init了
    // 也可以使用其他方式init
    int nums3[5];
    nums3[0] = 0;
    nums3[1] = 1;
    nums3[2] = 2;
    nums3[3] = 3;
    nums3[4] = 4;
    
    // 下面这种init也是准许的
    int nums4[] = {0, 1, 2, 3, 4};
    // 数组长度参数可以是变量
    int len = 1;
    while (len < 10)
    {
        int num_array2[len]; // variable-length array
        cout << sizeof(num_array2) << endl;
        len++;
    }
    //注意：下面这种初始化也是可以的，剩下的三位会被默认置0
    int nums2[5] = {0, 1}; 

    //注意 不可以使用下面的方式 原因很简单：numm是地址
    // int numm[10];
    // numm={1,1,1,1,1};

    // 下面是一个典型错误
    int array1[4] = {9, 8, 7, 6};
    int array2[4];
    // array2 = array1;       // error!array2是有值的 如果直接使array2指向array1 造成数据丢失 这是不被允许的
    array2[0] = array1[0]; // okay
    array2[1] = array1[1]; // okay
    array2[2] = array1[2]; // okay
    array2[3] = array1[3]; // okay

    // 特别注意 c和c++是没有 边界检查 的 下面的代码是可以正常运行的
    int nums[5] = {0, 1, 2, 3, 4};
    for (int i = -10; i < 6; i++)
    {
        cout << nums[i] << endl;
    }

    // 二维数组
    int mat[2][3] = {{11, 12, 13}, {14, 15, 16}};
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
            cout << mat[r][c] << ",";
        cout << endl;
    }

    // 将数组作为参数传入函数时
    // 不像java可以得到数组的长度，我们需要手动记忆数组长度，下面两个函数都是作为参数传入
    // int fun1(int nums[], int r);对于一维数组，传入时可以不指定大小，因为nums是首项地址且不进行边界检查
    // int fun1(int nums[][3], int r, int c);对于二维数组，传入时必须指定列大小

    // 可以使用const修饰数组 这是数组不准许再改变
    const float values[4] = {1.1f, 2.2f, 3.3f, 4.4f};
    //values[0] = 1.0f; // error
    
    return 0;
}
