#include <iostream>
#include <vector>
#include <queue>
#include "../Linked_List/LinkedList.h"
// #include "C:\Users\bhara\OneDrive\Desktop\DSA WITH CPP\All content\Linked_List\LinkedList.h"
using namespace std;



int main()
{

    LinkedList<int> list1;
    list1.insert(1);
    list1.insert(4);
    list1.insert(7);

    LinkedList<int> list2;
    list2.insert(2);
    list2.insert(5);
    list2.insert(8);

    LinkedList<int> list3;
    list3.insert(3);
    list3.insert(6);
    list3.insert(9);

    // Store all lists in a vector
    vector<LinkedList<int>> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
}