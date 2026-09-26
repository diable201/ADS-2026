#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s = {10, 15, 16, 13, 12, 14, 9, 8, 17};
    for (int x : s) cout << x << " ";                 // 8 9 10 12 13 14 15 16 17
    cout << "\n";
    cout << s.count(13) << " " << s.count(11) << "\n"; // 1 0
    cout << *s.begin() << " " << *s.rbegin() << "\n";  // 8 17
    cout << *s.lower_bound(11) << "\n";               // 12 — first value >= 11
    cout << *s.upper_bound(13) << "\n";               // 14 — first value > 13
    s.erase(13);
    for (auto it = s.lower_bound(11); it != s.end() && *it <= 15; ++it)
        cout << *it << " ";                           // 12 14 15
    cout << "\n";
    multiset<int> ms = {10, 10, 10, 9};
    cout << ms.count(10) << "\n";                     // 3
}
