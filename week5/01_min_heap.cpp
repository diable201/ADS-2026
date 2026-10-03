#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class MinHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        if (!a.empty())
            return a[0]; // O (1)
        throw out_of_range("cannot get the minimum of an empty heap");
    }

    void insert(int k) {
        a.push_back(k);

        int ind = a.size() - 1;

        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
        
        cout << "Inserted " << k << ", heap is now: " << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " " << endl;
        }
        
    }

    void heapify(int i) {
        int n = a.size();

        if (left(i) >= n) {
            return;
        }

        int j = left(i);

        if (right(i) < n && a[right(i)] < a[left(i)]) {
            j = right(i);
        }

        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int result = a[0];

        a[0] = a.back();
        a.pop_back();

        if (!a.empty()) {
            heapify(0);
        }

        return result;
    }

};

int main() {
    int n, x;
    cin >> n;

    MinHeap *heap = new MinHeap();

    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }

    for (int i = 0; i < n; i++) {
        cout << heap->extractMin() << " ";
    }

    return 0;
}