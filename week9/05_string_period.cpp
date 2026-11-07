#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1]; // fall back
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi = prefix_function(s);

    int len = n - pi[n - 1];
    if (n % len == 0)
        cout << s.substr(0, len) << " x " << n / len << endl;
    else
        cout << s << " x 1" << endl;
    return 0;
}