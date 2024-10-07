#include <iostream>
using namespace std;

enum datatype // 可以指定replace 以后TYPE_INT8代表1 TYPE_INT16代表2........
{
    TYPE_INT8 = 1,
    TYPE_INT16 = 2,
    TYPE_INT32 = 4,
    TYPE_INT64 = 8
};

struct Point
{
    // 可以理解为这个结构体有5个元素 一个type 其他四个是同一块地址的别名
    datatype type;
    union
    {
        int8_t data8[3];
        int16_t data16[3];
        int32_t data32[3];
        int64_t data64[3];
    };
};

size_t datawidth(Point pt)
{
    return size_t(pt.type) * 3;
}

int64_t l1norm(Point pt)
{
    int64_t result = 0;
    switch (pt.type)
    {
    case (TYPE_INT8):
        result = abs(pt.data8[0]) + abs(pt.data8[1]) + abs(pt.data8[2]); // abs是绝对值的意思
        break;
    case (TYPE_INT16):
        result = abs(pt.data16[0]) + abs(pt.data16[1]) + abs(pt.data16[2]);
        break;
    case (TYPE_INT32):
        result = abs(pt.data32[0]) + abs(pt.data32[1]) + abs(pt.data32[2]);
        break;
    case (TYPE_INT64):
        result = abs(pt.data64[0]) + abs(pt.data64[1]) + abs(pt.data64[2]);
        break;
    }
    return result;
}

int main()
{
    Point point1 = {.type = TYPE_INT8, .data8 = {-2, 3, 4}};
    Point point2 = {.type = TYPE_INT32, .data32 = {1, -2, 3}};

    cout << "Data width = " << datawidth(point1) << endl;
    cout << "Data width = " << datawidth(point2) << endl;

    cout << "L1 norm = " << l1norm(point1) << endl;
    cout << "L1 norm = " << l1norm(point2) << endl;

    return 0;
}