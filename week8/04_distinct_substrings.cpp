#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<ull> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] * 29;

    vector<ull> h(n);

    h[0] = s[0];
    for (int i = 1; i < n; i++)
        h[i] = h[i - 1] + s[i] * p[i];
    
    set<ull> hashes;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ull hash = h[j];
            if (i > 0)
                hash -= h[i - 1];
            hash *= p[n - 1 - i];
            hashes.insert(hash);
        }
    }

    cout << hashes.size() << endl;
    return 0;
}