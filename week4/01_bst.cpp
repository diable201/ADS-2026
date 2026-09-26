#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST {
public:
    Node *root = nullptr;

    // O(h)
    Node *insert(Node *node, int data) {
        if (node == nullptr) return new Node(data);
        if (data <= node->data) node->left = insert(node->left, data);  // equal values go left
        else                    node->right = insert(node->right, data);
        return node;
    }

    // O(h)
    Node *search(Node *node, int data) {
        if (node == nullptr || node->data == data) return node;
        if (data < node->data) return search(node->left, data);
        return search(node->right, data);
    }

    Node *findMin(Node *node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr) node = node->right;
        return node;
    }

    void inOrder(Node *node) {            // left → root → right : sorted
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node *node) {           // root → left → right : copy
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node *node) {          // left → right → root : delete
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    int getHeight(Node *node) {           // empty tree = 0, one node = 1
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int countNodes(Node *node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // O(h)
    Node *deleteNode(Node *node, int data) {
        if (node == nullptr) return nullptr;
        if (data < node->data)      node->left  = deleteNode(node->left, data);
        else if (data > node->data) node->right = deleteNode(node->right, data);
        else {
            if (node->left == nullptr && node->right == nullptr) {   // leaf
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) {                             // right child only
                Node *r = node->right;
                delete node;
                return r;
            }
            if (node->right == nullptr) {                            // left child only
                Node *l = node->left;
                delete node;
                return l;
            }
            Node *pred = findMax(node->left);                        // two children
            node->data = pred->data;
            node->left = deleteNode(node->left, pred->data);
        }
        return node;
    }

    void destroy(Node *node) {            // post-order: children first, then parent
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
    ~BST() { destroy(root); }
};

int main() {
    BST bst;
    int order[] = {10, 15, 16, 13, 12, 14, 9, 8, 17};
    for (int x : order) bst.root = bst.insert(bst.root, x);

    cout << "in:   "; bst.inOrder(bst.root);   cout << "\n";   // 8 9 10 12 13 14 15 16 17
    cout << "pre:  "; bst.preOrder(bst.root);  cout << "\n";   // 10 9 8 15 13 12 14 16 17
    cout << "post: "; bst.postOrder(bst.root); cout << "\n";   // 8 9 12 14 13 17 16 15 10

    cout << "min " << bst.findMin(bst.root)->data               // 8
         << ", max " << bst.findMax(bst.root)->data << "\n";    // 17
    cout << "height " << bst.getHeight(bst.root)                // 4
         << ", nodes " << bst.countNodes(bst.root) << "\n";     // 9

    cout << "search 13: " << (bst.search(bst.root, 13) ? "found" : "not found") << "\n";
    cout << "search 11: " << (bst.search(bst.root, 11) ? "found" : "not found") << "\n";

    bst.root = bst.deleteNode(bst.root, 13);                    // two children -> 12 takes its place
    cout << "after delete 13, pre: "; bst.preOrder(bst.root); cout << "\n";  // 10 9 8 15 12 14 16 17
    bst.root = bst.deleteNode(bst.root, 10);                    // root -> 9 takes its place
    cout << "after delete 10, pre: "; bst.preOrder(bst.root); cout << "\n";  // 9 8 15 12 14 16 17
    return 0;
}
