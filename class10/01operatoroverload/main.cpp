#include <iostream>
#include "time.hpp"

using namespace std;

int main()
{
    MyTime t1(2, 40);
    MyTime t2(1, 20);
    cout << (t1 + t2).getTime() << endl;

    // 下面2个等效
    t1 += t2;
    t1.operator+=(t2);

    cout << t1.getTime() << endl;

    // 下面2个等效
    t1 += 30;          
    t1.operator+=(30); 

    return 0;
}