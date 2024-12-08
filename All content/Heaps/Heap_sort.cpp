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

    // Helper function 0to maintain the heap property from the root to a child
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
    void heapsort(vector<int> &ans)
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }
        int minValue = heap[0];
        ans.push_back(minValue);
        heap[0] = heap.back();
        heap.pop_back();
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
        return;
    }

    // Time complexity: O(n log n)

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
    void printHeap() 
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
    heap.insert(22);
    heap.insert(5);
    heap.insert(30);
    heap.insert(4);

    cout << "Min-Heap elements: ";
    heap.printHeap();

    cout << "Min value: " << heap.getMin() << endl;
    vector<int> ans;
    for (int i = 0; i < 5; i++)
    {
        heap.heapsort(ans);
    }

    for (int i : ans)
    {
        cout << i << ' ';
    }
    // cout << "Heap after extraction: ";
    // heap.printHeap();

    return 0;
}
//  void heapSort(vector<int> &arr)
//     {
//         heap = arr; 

//         int n = heap.size();
//         for (int i = n / 2 - 1; i >= 0; i--)
//         {
//             heapifyDown(i, n);
//         }

//         for (int i = n - 1; i > 0; i--)
//         {
//             swap(heap[0], heap[i]); 
//             heapifyDown(0, i);     
//         }

//         arr = heap; 
//     }


// void heapSort(int arr[], int n) {
//     // Step 1: Build max-heap
//     for (int i = n / 2 - 1; i >= 0; i--) {
//         heapifyDown(arr, n, i);
//     }

//     // Step 2: Extract elements from heap one by one
//     for (int i = n - 1; i > 0; i--) {
//         // Swap root with the last element
//         swap(&arr[0], &arr[i]);

//         // Restore heap property for the reduced heap
//         heapifyDown(arr, i, 0);
//     }
// }