#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& a) {
    int n = static_cast<int>(a.size());

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        // The last i elements are already in their final positions.
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        // A full pass without swaps means the array is sorted.
        if (!swapped) {
            break;
        }
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

    bubbleSort(a);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}
