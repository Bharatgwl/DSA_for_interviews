#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    list.insert(50);
    list.insert(0);
    list.insert(40);
    list.insert(350);
    list.insert(20);
    list.insert(10);
    list.insert(2);
    list.insert(-10);
    list.insert(120);
    list.insert(109);
    list.insert(0);
    list.insert(130);

    cout << "Initial list: ";

    list.display();
    list.Sort();
    list.display();
    

    return 0;
}