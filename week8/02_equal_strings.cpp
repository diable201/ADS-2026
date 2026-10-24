#include <iostream>
#include <vector>
#include <map>
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
    vector<string> s(n);
    vector<ull> hs(n);

    map<ull, vector<int>> groups; // hash -> indices

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        hs[i] = get_hash(s[i]);
        groups[hs[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j : groups[hs[i]]) {
            if (j > i && s[i] == s[j]) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}