#include <iostream>
using namespace std;
struct Node { int data; Node *left = nullptr, *right = nullptr; Node(int d) : data(d) {} };
Node *insert(Node *n, int x) {
    if (!n) return new Node(x);
    if (x <= n->data) n->left = insert(n->left, x); else n->right = insert(n->right, x);
    return n;
}
int visited = 0;
void range(Node *node, int lo, int hi) {
    if (node == nullptr) return;
    visited++;
    if (lo < node->data)  range(node->left, lo, hi);    // the left subtree may contain values >= lo
    if (lo <= node->data && node->data <= hi) cout << node->data << " ";
    if (node->data < hi)  range(node->right, lo, hi);   // the right subtree may contain values <= hi
}
int main() {
    Node *root = nullptr;
    for (int x : {10, 15, 16, 13, 12, 14, 9, 8, 17}) root = insert(root, x);
    range(root, 11, 15);                       // 12 13 14 15
    cout << "\nvisited " << visited << " of 9 nodes\n";
}
