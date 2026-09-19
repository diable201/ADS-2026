// Precondition: a is sorted non-decreasing. Inclusive range [l, r].
//   invariant: if x is in the array, its index is inside [l, r]
#include <iostream>
#include <vector>
using namespace std;

int binary_search_exact(vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;   // NOT (l + r) / 2 — that overflows
        if (a[mid] == x) return mid;
        if (a[mid] <  x) l = mid + 1;
        else             r = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> a = {3, 5, 8, 13, 18, 19, 21, 27, 32};
    cout << binary_search_exact(a, 13) << "\n";   // 3  (4 comparisons)
    cout << binary_search_exact(a, 3)  << "\n";   // 0
    cout << binary_search_exact(a, 32) << "\n";   // 8
    cout << binary_search_exact(a, 20) << "\n";   // -1

    vector<int> empty_v;                 // edge cases: sizes 0, 1, 2
    vector<int> one = {7};
    vector<int> two = {7, 7};
    cout << binary_search_exact(empty_v, 7) << "\n";  // -1
    cout << binary_search_exact(one, 7)     << "\n";  // 0
    cout << binary_search_exact(two, 7)     << "\n";  // 0 or 1 — any occurrence
    return 0;
}
