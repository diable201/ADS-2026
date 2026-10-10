#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n) || n < 0) {
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}
