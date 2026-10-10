#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    // Save the pivot VALUE; the array element itself may move.
    int pivot = a[l + (r - l) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    // Partition boundaries are j and i, not the pivot's index.
    if (l < j) {
        quickSort(a, l, j);
    }

    if (i < r) {
        quickSort(a, i, r);
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

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}
