
class Student
{
private:
    const int BMI = 24;//成员变量被const修饰 则不可以更改
    // ...
public:
    Student()
    {
        //BMI = 25; err
        // ...
    }

    int getBorn() const   //成员函数被const修饰 则在其中不可以修改成员变量
    {
        //born++; err
        return 0;
    }
};