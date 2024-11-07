#include <iostream>
#include <stack>
using namespace std;
class twostack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    twostack(int s)
    {
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }
    ~twostack(){
        delete []arr;
    }
    void push1(int num)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
            cout << "Over flow" << endl;
        }
    }
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
            cout << "Over flow" << endl;
        }
    }
    void tops1()
    {
        if (top1 > -1)
        {
            cout << arr[top1] << endl;
        }
        else
        {
            cout << "stack1 is empty";
        }
    }
    void tops2()
    {
        if (top2 < size)
        {
            cout << arr[top2]<<endl;
        }
        else
        {
            cout << "stack2 is empty" << endl;
        }
    }
    void pop1()
    {
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "under flow" << endl;
        }
    }
    void pop2()
    {
        if (top1 < size)
        {
            top1++;
        }
        else
        {
            cout << "under flow" << endl;
        }
    }
};

int main()
{
    twostack s1(8);

    s1.push1(1);
    s1.push1(2);
    s1.push1(3);
    s1.push1(4);
    s1.push2(5);
    s1.push2(6);
    s1.push2(7);
    s1.push2(8);
    s1.tops2();
    s1.pop1();
    s1.tops1();
}