// The traps, made visible.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // TRAP 1 — overflow in (l + r) / 2
    int l = 2000000000, r = 2000000001;
    int bad  = (l + r) / 2;          // undefined behaviour: the sum wraps negative
    int good = l + (r - l) / 2;      // correct, always
    cout << bad << " " << good << "\n";   // e.g. -147483647   2000000000

    // TRAP 2 — the infinite loop.
    // With while (l <= r) and l = mid (no +1), take r == l + 1:
    //   mid == l, then l = mid == l, nothing changes, the loop never exits.
    // Uncomment to watch it hang:
    // int L = 0, R = 1; while (L <= R) { int mid = L + (R - L) / 2; L = mid; }

    // TRAP 3 — unsorted input: no crash, just a confident wrong answer
    vector<int> messy = {18, 3, 27, 5};
    int x = 5, lo = 0, hi = 3, found = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (messy[mid] == x) { found = mid; break; }
        if (messy[mid] < x) lo = mid + 1; else hi = mid - 1;
    }
    cout << found << "\n";   // -1, although 5 is right there at index 3
    return 0;
}
