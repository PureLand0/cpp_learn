#include <iostream>
using namespace std;

class Student
{
public:
    char name[4];
    int born;
    bool male;
};

int main()
{
    Student *s = new Student();
    s->born = 110;
    cout << s->born << endl;

    return 0;
}
