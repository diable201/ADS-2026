// 11. Doubly linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
public:
    Node *tail, *front;

    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    ~LinkedList() {
        while (front != NULL) pop_front();
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {              // empty list: both ends move
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail == NULL) return;
        Node *old = tail;
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
        else              front = NULL;   // the list just became empty
        delete old;
    }

    void pop_front() {
        if (front == NULL) return;
        Node *old = front;
        front = front->next;
        if (front != NULL) front->prev = NULL;
        else               tail = NULL;
        delete old;
    }

    void del_node(Node *node) {
        if (node == NULL)      return;
        if (node == front)   { pop_front(); return; }
        if (node == tail)    { pop_back();  return; }
        node->prev->next = node->next;     // bridge forward
        node->next->prev = node->prev;     // bridge backward
        delete node;
    }

    void insert_node(Node *node1, int data) {
        if (node1 == NULL) return;
        if (node1 == tail) { push_back(data); return; }   // check BEFORE new
        Node *node  = new Node(data);
        Node *node2 = node1->next;
        node1->next = node;
        node->prev  = node1;
        node->next  = node2;
        node2->prev = node;
    }

    Node* find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data) return node;
            node = node->next;
        }
        return NULL;                        // O(n)
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    void print_reverse() {                  // proves prev is wired correctly
        Node *node = tail;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->prev;
        }
        cout << endl;
    }
};

int main() {
    LinkedList *ll = new LinkedList();

    ll->push_back(5);
    ll->push_back(6);
    ll->push_back(7);
    ll->push_back(8);
    ll->push_back(9);
    ll->push_back(10);
    ll->push_front(11);
    ll->push_front(12);
    ll->push_front(13);
    ll->push_front(14);
    ll->push_front(15);
    ll->print();                            // 15 14 13 12 11 5 6 7 8 9 10
    ll->print_reverse();                    // 10 9 8 7 6 5 11 12 13 14 15
    cout << ll->front->data << " " << ll->tail->data << endl;   // 15 10

    ll->pop_back();
    ll->pop_back();
    ll->pop_front();
    ll->pop_front();
    ll->print();                            // 13 12 11 5 6 7 8
    cout << ll->front->data << " " << ll->tail->data << endl;   // 13 8

    Node *node = ll->find_node(11);
    if (node != NULL) ll->del_node(node);
    ll->print();                            // 13 12 5 6 7 8

    node = ll->find_node(6);
    ll->insert_node(node, 100);
    ll->print();                            // 13 12 5 6 100 7 8
    ll->print_reverse();                     // 8 7 100 6 5 12 13

    delete ll;
    return 0;
}
