#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

// O(m)
ull get_hash(string s) {
    ull p = 29;
    ull p_pow = 1; // p^0

    ull h = 0;

    for (size_t i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << s << " " << get_hash(s) << endl;
    }
    return 0;
}