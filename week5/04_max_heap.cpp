#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
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

    int getMax() {
        if (!a.empty())
            return a[0]; // O (1)
    }

    void insert(int k) {
        a.push_back(k);

        int ind = a.size() - 1;

        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        int n = a.size();

        if (left(i) >= n) {
            return;
        }

        int j = left(i);

        if (right(i) < n && a[right(i)] > a[left(i)]) {
            j = right(i);
        }

        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    MaxHeap *heap = new MaxHeap();
    for (int i = 0; i < n; i++)
        heap->insert(arr[i]);
    for (int i = 0; i < n; i++)
        cout << heap->extractMax() << " ";
    return 0;
}