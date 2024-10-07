#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //while
    int num = 10;
    while(num > 0)
    {
        cout << "num = " << num << endl;
        num--;
    }

    //do while
    int i = 10;
    do{
        cout << 1 << endl;
        i--;
    }while (i > 0);
    
    
    //for
    for (int i = 0; i < 10; i++)
    {
        cout << 1 << endl;
    }
    
    //注意break continue的作用
    
        
    return 0;
}
