// 9. Minimum operations to turn a into b:  x+1, x-1, x*2, x/2
//    BFS = shortest path when every operation costs 1.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int LIM = 2000;      // upper bound on values; must be >= b
int par[LIM + 1];          // -1 = not visited yet, otherwise = where we came from

int f(int a, int b) {
    for (int i = 0; i <= LIM; i++)
        par[i] = -1;

    queue<pair<int, int> > q;     // (value, number of steps)
    q.push(make_pair(a, 0));
    par[a] = a;                   // the start is its own parent

    while (!q.empty()) {
        int x = q.front().first;
        int d = q.front().second;
        q.pop();

        if (x == b) return d;

        int nxt[4] = {x + 1, x - 1, x * 2, x / 2};
        for (int i = 0; i < 4; i++) {
            int y = nxt[i];
            if (y < 0 || y > LIM) continue;   // never index outside the array
            if (par[y] != -1)     continue;   // already reached, and by a shorter path
            par[y] = x;
            q.push(make_pair(y, d + 1));
        }
    }
    return -1;                    // b is not reachable
}

int main() {
    int a, b;
    cin >> a >> b;

    int steps = f(a, b);
    cout << steps << endl;
    if (steps < 0) return 0;

    vector<int> path;             // walk the parents back from b
    path.push_back(b);
    int t = b;
    while (par[t] != t) {
        t = par[t];
        path.push_back(t);
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
    return 0;
}
