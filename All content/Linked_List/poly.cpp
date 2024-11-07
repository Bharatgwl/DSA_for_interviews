#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node *next;

    Node(int pow, int coeff) {
        this->coeff = coeff;
        this->pow = pow;
        this->next = nullptr;
    }
};

void insertattail(Node *&tail, int pow, int coeff) {
    Node *temp = new Node(pow, coeff);
    tail->next = temp;
    tail = temp;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != nullptr) {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}

Node* addpolynomial(Node *head1, Node *head2) {
    Node *resultHead = nullptr, *resultTail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        Node *temp = nullptr;
        if (head1->pow == head2->pow) {
            temp = new Node(head1->pow, head1->coeff + head2->coeff);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->pow > head2->pow) {
            temp = new Node(head1->pow, head1->coeff);
            head1 = head1->next;
        } else {
            temp = new Node(head2->pow, head2->coeff);
            head2 = head2->next;
        }

        if (resultHead == nullptr) {
            resultHead = temp;
            resultTail = temp;
        } else {
            resultTail->next = temp;
            resultTail = temp;
        }
    }


    while (head1 != nullptr) {
        Node *temp = new Node(head1->pow, head1->coeff);
        resultTail->next = temp;
        resultTail = temp;
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        Node *temp = new Node(head2->pow, head2->coeff);
        resultTail->next = temp;
        resultTail = temp;
        head2 = head2->next;
    }

    return resultHead;
}

int main() {
    Node *n = new Node(4, 1000);
    Node *n1 = new Node(4, 500);
    Node *head = n;
    Node *tail = n;
    Node *head1 = n1;
    Node *tail1 = n1;

    int s;

    cin >> s;
    int pow[s];
    int coeff[s];
    int pow1[s];
    int coeff1[s];

    
    for (int i = 0; i < s; i++) {
        cin >> pow[i] >> coeff[i];
        insertattail(tail, pow[i], coeff[i]);
    }

   
    for (int i = 0; i < s; i++) {
        cin >> pow1[i] >> coeff1[i];
        insertattail(tail1, pow1[i], coeff1[i]);
    }

   
    print(head);

    
    print(head1);

    Node *head3 = addpolynomial(head, head1);

    cout << "Result polynomial after addition: ";
    print(head3);

    return 0;
}