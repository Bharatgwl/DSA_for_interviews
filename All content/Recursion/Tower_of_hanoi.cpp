#include <iostream>
using namespace std;
void tower_of_hanoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout << "move disk " << n << "from" << a << " to " << c << endl;
        return;
    }
    tower_of_hanoi(n - 1, a, c, b);
    cout << "move disk " << n << "from" << a << " to " << c << endl;
    tower_of_hanoi(n - 1, b, a, c);
}

int main()
{
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3;
    tower_of_hanoi(n, a, b, c);
}