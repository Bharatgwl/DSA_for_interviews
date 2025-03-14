#include <iostream>
#include <cstring>
using namespace std;
class stack
{
private:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    stack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freespot = 0;
    }
    void topele(int m)
    {
        if (freespot == 0)
        {
            cout << "stack is empty";
            return;
        }
        int index = top[m - 1];
        cout << arr[index];
    }
    bool push(int x, int m) // m'th stack
    {
        if (freespot == -1)
        {
            cout << "overflow";
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
    }
    bool pop(int m)
    {
        if (top[m] == -1)
        {
            cout << "underflow";
            return false;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
    }
};
int main()
{
    stack st(3, 6);
    st.push(1, 1);
    st.push(10, 2);
    st.push(20, 2);
    st.push(30, 2);
    st.push(40, 3);
    st.push(50, 3);

    st.topele(2);
    st.pop(1);
    st.pop(2);
    st.pop(2);
    st.pop(2);
    st.pop(3);
    st.pop(3);
   
    st.topele(2);
}