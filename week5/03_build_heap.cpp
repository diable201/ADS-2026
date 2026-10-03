#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    public:
    vector<int> a;

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void heapify(int i) {
        int n = a.size();
        if (left(i) >= n)
            return;
        int j = left(i);
        if (right(i) < n && a[right(i)] < a[left(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    void buildHeap(vector<int> arr) {
        a = arr;
        for (int i = a.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    MinHeap *heap = new MinHeap();
    heap->buildHeap(arr);
    for (int i = 0; i < n; i++)
        cout << heap->a[i] << " ";
    return 0;
}
