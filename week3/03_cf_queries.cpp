// Lecture 3 — Slide 11. Codeforces EDU, binary search, problem A.
// n sorted numbers, k queries, print YES / NO. Total O((n + k) log n).
// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <iostream>
#include <vector>
using namespace std;

bool find_value(vector<int> &a, int x) {   // pass by reference — a copy per query is O(n)
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return true;
        if (a[m] < x) l = m + 1;
        else          r = m - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);   // without these two lines: TLE on 1e5 lines
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        cout << (find_value(a, x) ? "YES\n" : "NO\n");   // "\n", never endl
    }
    return 0;
}
// sample input:
// 5 3
// 1 5 8 12 13
// 8 1 23
// sample output:
// YES
// YES
// NO
