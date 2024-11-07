#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    // Helper function to maintain the heap property from a child to the root
    void heapifyUp(int index)
    {
        int parentIndex = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parentIndex])
        {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    // Helper function to maintain the heap property from the root to a child
    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to remove and return the minimum element (root) from the heap
    int extractMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    // Function to get the minimum element (root) without removing it
    int getMin() const
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Function to print the elements of the heap
    void printHeap() const
    {
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(40);

    cout << "Min-Heap elements: ";
    heap.printHeap();

    cout << "Min value: " << heap.getMin() << endl;

    cout << "Extract min: " << heap.extractMin() << endl;

    cout << "Heap after extraction: ";
    heap.printHeap();

    return 0;
}
