#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[100000];
int color[100000];
int n, m;

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (color[to] == -1) {
                color[to] = 1 - color[v]; // the other color
                q.push(to);
            } else if (color[to] == color[v]) {
                return false; // 2 neighbors with one color
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int v = 0; v < n; v++) {
        color[v] = -1; // -1 means no color yet
    }
    
    for (int v = 0; v < n; v++) {
        if (color[v] == -1 && !bfs(v)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}