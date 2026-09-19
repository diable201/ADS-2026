// All of these require a sorted range.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {1, 4, 4, 4, 9, 12, 12, 15};

    int x = 4;
    auto it = lower_bound(a.begin(), a.end(), x);   // first element >= x
    auto jt = upper_bound(a.begin(), a.end(), x);   // first element  > x

    cout << (it - a.begin()) << "\n";               // 1  — index of the first 4
    cout << (jt - it)        << "\n";               // 3  — how many elements equal 4
    cout << (it - a.begin()) << "\n";               // 1  — how many are  < 4
    cout << (jt - a.begin()) << "\n";               // 4  — how many are <= 4

    // how many lie in [L, R]
    int L = 4, R = 12;
    cout << (upper_bound(a.begin(), a.end(), R) - lower_bound(a.begin(), a.end(), L)) << "\n";  // 6

    // is x present
    cout << binary_search(a.begin(), a.end(), 9) << "\n";    // 1
    cout << (it != a.end() && *it == x)          << "\n";    // 1 — same check by hand

    // nearest value to x by |a[i] - x|: look at BOTH neighbours, never guess the side
    int q = 11;
    auto up = lower_bound(a.begin(), a.end(), q);
    int best = *up;
    if (up != a.begin() && q - *prev(up) <= *up - q) best = *prev(up);
    cout << best << "\n";                                    // 12
    return 0;
}

