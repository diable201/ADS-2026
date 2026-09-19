// invariant: a[l] <= x  and  a[r] > x   (a[-1] = -inf, a[n] = +inf)
// One template answers both questions and never returns "not found".
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int,int> nearest_elements(vector<int>& a, int x) {
    int n = (int)a.size();
    int l = -1, r = n;               // conceptual -inf and +inf; never read

    while (l + 1 < r) {              // stop when they are adjacent
        int mid = l + (r - l) / 2;
        if (a[mid] <= x) l = mid;    // mid is allowed to be the new left border
        else             r = mid;
    }

    int leftVal  = (l >= 0 ? a[l] : INT_MIN);   // x is below everything
    int rightVal = (r <  n ? a[r] : INT_MAX);   // x is above everything
    return {leftVal, rightVal};
}

// same loop, one sign changed: l lands just before the FIRST occurrence of x
int lower_bound_index(vector<int>& a, int x) {
    int l = -1, r = (int)a.size();
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < x) l = mid;
        else            r = mid;
    }
    return r;                        // first index with a[r] >= x
}

int main() {
    vector<int> a = {3, 5, 10, 11, 13, 18, 25, 27, 31};

    auto [lo, hi] = nearest_elements(a, 20);
    cout << lo << " " << hi << "\n";               // 18 25   (3 iterations)

    auto [lo2, hi2] = nearest_elements(a, 1);
    cout << (lo2 == INT_MIN) << " " << hi2 << "\n";  // 1 3   — nothing on the left

    auto [lo3, hi3] = nearest_elements(a, 99);
    cout << lo3 << " " << (hi3 == INT_MAX) << "\n";  // 31 1  — nothing on the right

    vector<int> dup = {1, 4, 4, 4, 9};
    cout << lower_bound_index(dup, 4) << "\n";      // 1 — first occurrence
    return 0;
}
