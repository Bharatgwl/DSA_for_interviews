#include <iostream>
using namespace std;
class Heap
{
private:
    int *arr;
    int i = 0;
    int size;

public:
    Heap(int size)
    {
        cout<<"constructor is called"<<endl;
        this->size = size;
        arr = new int(size);
    }
    void print()
    {
        for (int j = 1; j <= i; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    void insert(int val)
    {
        if (i == size)
        {
            cout << "Heap overflow " << endl;
            return;
        }
        int index = ++i;
        if (index <= size)
        {
            arr[index] = val;
        }
        while (index > 1) // percolate UP
        {
            int parentindex = index / 2;
            if (arr[parentindex] < arr[index])
            {
                swap(arr[parentindex], arr[index]);
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
        if (i == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[i];
        i--; // Reduce heap size

        int rootIndex = 1;
        while (rootIndex <= i)
        {
            int leftChildIndex = 2 * rootIndex;
            int rightChildIndex = 2 * rootIndex + 1;
            int largest = rootIndex;

            // Find the largest among root, left child, and right child
            if (leftChildIndex <= i && arr[leftChildIndex] > arr[largest])
            {
                largest = leftChildIndex;
            }
            if (rightChildIndex <= i && arr[rightChildIndex] > arr[largest])
            {
                largest = rightChildIndex;
            }

            // If the root is already the largest, stop
            if (largest == rootIndex)
            {
                break;
            }

            // Swap root with the largest child
            swap(arr[rootIndex], arr[largest]);
            rootIndex = largest; // Move to the largest child
        }
    }
    ~Heap(){
        cout<<"desturctor is called"<<endl;
        delete[] arr;
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
    h1.print(); // remove root which is 55
    // h1.inserlt(2);
}