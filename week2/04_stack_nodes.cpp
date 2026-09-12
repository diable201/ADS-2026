// 4. Stack built from nodes
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) { this->data = data; this->next = NULL; }
};

class Stack {
public:
    Node *top;
    int sz;

    Stack() { top = NULL; sz = 0; }

    ~Stack() { while (!empty()) pop(); }

    void push(int data) {
        Node *node = new Node(data);
        node->next = top;          // 1. point at the old top
        top = node;                // 2. become the new top
        sz++;
    }

    void pop() {
        if (top == NULL) return;
        Node *old = top;           // 1. save the address
        top = top->next;           // 2. unlink
        delete old;                // 3. free
        sz--;
    }

    int peek() { return top->data; }   // caller must check empty() first
    int size() { return sz; }
    bool empty() { return sz == 0; }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(15);
    st.push(1);

    cout << st.peek() << endl;       // 1
    st.pop();
    st.pop();
    cout << st.peek() << endl;       // 20
    cout << st.size() << endl;       // 2
    cout << st.empty() << endl;      // 0

    while (!st.empty()) {
        cout << st.peek() << " ";
        st.pop();
    }
    cout << endl;                    // 20 10

    st.pop();                        // safe on an empty stack
    return 0;
}
