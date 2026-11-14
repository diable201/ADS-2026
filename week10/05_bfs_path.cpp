#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[100000];
bool used[100000];
int p[100000];
int n, m;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                p[to] = v; // we came to "to" from v
                q.push(to);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s, t;
    cin >> s >> t;

    bfs(s);

    if (!used[t]) {
        cout << "NO PATH" << endl;
        return 0;
    }

    vector<int> path;
    for (int v = t; v != -1; v = p[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}