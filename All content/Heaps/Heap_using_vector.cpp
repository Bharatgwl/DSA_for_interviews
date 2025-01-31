#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> arr;

public:
    Heap(int size)
    {
        arr.reserve(size);
    }
    void print()
    {
        for (int val : arr)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    void insert(int val)
    {
        if (arr.size() == arr.capacity())
        {
            cout << "Heap overflow " << endl;
            return;
        }
        arr.push_back(val);
        int index = arr.size() - 1;
        while (index > 0) // percolate UP
        {
            int parentindex = (index - 1) / 2;
            if (arr[parentindex] < arr[index])
            {
                std::swap(arr[parentindex], arr[index]);
                index = parentindex;
            }
            else
            {
                return;
            }
        }
    }
    void remove()
    {
        if (arr.empty())
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[0] = arr.back();
        arr.pop_back(); // Reduce heap size

        int rootIndex = 0;
        while (rootIndex < arr.size())
        {
            int leftChildIndex = 2 * rootIndex + 1;
            int rightChildIndex = 2 * rootIndex + 2;
            int largest = rootIndex;

            // Find the largest among root, left child, and right child
            if (leftChildIndex < arr.size() && arr[leftChildIndex] > arr[largest])
            {
                largest = leftChildIndex;
            }
            if (rightChildIndex < arr.size() && arr[rightChildIndex] > arr[largest])
            {
                largest = rightChildIndex;
            }

            // If the root is already the largest, stop
            if (largest == rootIndex)
            {
                break;
            }

            // Swap root with the largest child
            std::swap(arr[rootIndex], arr[largest]);
            rootIndex = largest; // Move to the largest child
        }
    }
};
int main()
{
    // Heap *h1 = new Heap(10);
    Heap h1(6);
    h1.insert(70);
    h1.insert(50);
    h1.insert(55);
    h1.insert(40);
    h1.insert(30);
    h1.insert(45);
    h1.print();
    h1.remove(); // remove root which is 70
    h1.print();
    h1.remove(); // remove root which is 55
    h1.print(); 
    // h1.inserlt(2);
}