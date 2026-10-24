#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

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

vector<ull> get_h(string s) {
    int n = s.size();
    vector<ull> h(n);
    h[0] = s[0];
    ull p = 29;
    ull p_pow = 29; // p^1

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<ull> p(n);
    p[0] = 1;

    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * 29;
    }

    ull h_s2 = get_hash(s2);
    vector<ull> h = get_h(s1);

    for (int i = 0; i + m <= n; i++) {
        int j = i + m - 1;
        ull hash = h[j]; // hash of s1[i...j], multiplied by p^i
        if (i > 0)
            hash -= h[i - 1];
        if (hash == h_s2 * p[i])
            cout << i << " ";
    }
    return 0;
}