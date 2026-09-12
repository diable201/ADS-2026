// 1. Node — the building block
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;

    cout << n1->data << endl;                    // 10
    cout << n1->next->data << endl;              // 20
    cout << n1->next->next->data << endl;        // 30

    // walk the whole chain
    for (Node *p = n1; p != nullptr; p = p->next)
        cout << p->data << " ";
    cout << endl;                                // 10 20 30

    delete n3; delete n2; delete n1;
    return 0;
}
