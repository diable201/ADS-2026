#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Repair the max-heap inside a[0..n-1], starting at index i.
// The subtrees of i must already be valid max-heaps.
void siftDown(vector<int>& a, int n, int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest == i) {
            return;
        }

        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(vector<int>& a) {
    int n = static_cast<int>(a.size());

    // Build a max-heap from the bottom up.
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(a, n, i);
    }

    // Put the maximum at the end of the remaining heap.
    for (int end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);
        siftDown(a, end, 0);
    }
}

int main() {
    int n;
    if (!(cin >> n) || n < 0) {
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    heapSort(a);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}
