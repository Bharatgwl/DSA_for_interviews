// #include <iostream>
// #include <queue>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int value) : data(value), left(nullptr), right(nullptr) {}
// };

// class MinHeap {
// private:
//     Node* root;

//     // Function to insert a new node at the correct position in the tree
//     void insertNode(Node* &node, int value) {
//         if (!node) {
//             node = new Node(value);
//         } else {
//             // Use level-order traversal to find the right position
//             queue<Node*> q;
//             q.push(node);
//             while (!q.empty()) {
//                 Node* temp = q.front();
//                 q.pop();

//                 if (!temp->left) {
//                     temp->left = new Node(value);
//                     return;
//                 } else {
//                     q.push(temp->left);
//                 }

//                 if (!temp->right) {
//                     temp->right = new Node(value);
//                     return;
//                 } else {
//                     q.push(temp->right);
//                 }
//             }
//         }
//     }

//     // Function to heapify up after insertion to maintain the min-heap property
//     void heapifyUp(Node* node) {
//         if (!node || !node->left) return;

//         if (node->left && node->data > node->left->data) {
//             swap(node->data, node->left->data);
//             heapifyUp(node->left);
//         }

//         if (node->right && node->data > node->right->data) {
//             swap(node->data, node->right->data);
//             heapifyUp(node->right);
//         }
//     }

//     // Function to perform heapify down after extraction
//     void heapifyDown(Node* node) {
//         if (!node) return;

//         Node* smallest = node;

//         if (node->left && node->left->data < smallest->data)
//             smallest = node->left;

//         if (node->right && node->right->data < smallest->data)
//             smallest = node->right;

//         if (smallest != node) {
//             swap(node->data, smallest->data);
//             heapifyDown(smallest);
//         }
//     }

//     // Function to get the last node (used during extract)
//     Node* getLastNode(Node* node) {
//         if (!node) return nullptr;

//         queue<Node*> q;
//         q.push(node);
//         Node* temp;

//         while (!q.empty()) {
//             temp = q.front();
//             q.pop();

//             if (temp->left)
//                 q.push(temp->left);
//             if (temp->right)
//                 q.push(temp->right);
//         }

//         return temp;
//     }

//     // Function to delete the last node
//     void deleteLastNode(Node* root, Node* lastNode) {
//         queue<Node*> q;
//         q.push(root);

//         while (!q.empty()) {
//             Node* temp = q.front();
//             q.pop();

//             if (temp->left) {
//                 if (temp->left == lastNode) {
//                     delete temp->left;
//                     temp->left = nullptr;
//                     return;
//                 } else {
//                     q.push(temp->left);
//                 }
//             }

//             if (temp->right) {
//                 if (temp->right == lastNode) {
//                     delete temp->right;
//                     temp->right = nullptr;
//                     return;
//                 } else {
//                     q.push(temp->right);
//                 }
//             }
//         }
//     }

// public:
//     MinHeap() : root(nullptr) {}

//     // Function to insert a value into the heap
//     void insert(int value) {
//         insertNode(root, value);
//         heapifyUp(root);
//     }

//     // Function to extract the minimum (root) value from the heap
//     int extractMin() {
//         if (!root) {
//             cout << "Heap is empty!" << endl;
//             return -1;
//         }

//         int minValue = root->data;

//         Node* lastNode = getLastNode(root);
//         if (lastNode) {
//             root->data = lastNode->data;
//             deleteLastNode(root, lastNode);
//             heapifyDown(root);
//         }

//         return minValue;
//     }

//     // Function to print the heap using level-order traversal
//     void printHeap() {
//         if (!root) {
//             cout << "Heap is empty!" << endl;
//             return;
//         }

//         queue<Node*> q;
//         q.push(root);

//         while (!q.empty()) {
//             Node* temp = q.front();
//             q.pop();

//             cout << temp->data << " ";

//             if (temp->left)
//                 q.push(temp->left);
//             if (temp->right)
//                 q.push(temp->right);
//         }

//         cout << endl;
//     }
// };

// int main() {
//     MinHeap heap;

//     heap.insert(10);
//     heap.insert(20);
//     heap.insert(5);
//     heap.insert(30);
//     heap.insert(40);

//     cout << "Min-Heap elements: ";
//     heap.printHeap();

//     cout << "Extract min: " << heap.extractMin() << endl;

//     cout << "Heap after extraction: ";
//     heap.printHeap();

//     return 0;
// }
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
