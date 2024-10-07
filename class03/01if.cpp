#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // e1
    int num = 7;
    if (num == 5)
    {
        cout << "The number is 5." << endl;
    }

    // e2
    if (num == 5)
    {
        cout << "The number is 5." << endl;
    }
    else
    {
        cout << "The number is not 5." << endl;
    }

    // e3
    if (num < 5)
    {
        cout << "The number is less than 5." << endl;
    }
    else if (num > 10)
    {
        cout << "The number is greater than 10." << endl;
    }
    else
    {
        cout << "The number is in range [5, 10]." << endl;
    }

    // if()括号里的表达式应该返回true或者false 可以有> < == >= <= && ||等
    //&&：与，如果只有一个，则代表按位与
    //||：或，如果只有一个，则代表按位或

    // e4
    char input_char;
    cin >> input_char;
    
    switch (input_char)
    {
    case 'a':
    case 'A':
        cout << "Move left." << endl;
        break;//一定要有 没有的话从匹配处依次执行
    case 'd':
    case 'D':
        cout << "Move right." << endl;
        break;
    default:
        cout << "Undefined key." << endl;
        break;
    }

    return 0;
}
