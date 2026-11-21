#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[100000];
bool used[100000];
int tin[100000];  // time when we entered the vertex
int low[100000];  // the smallest tin we can reach from below
int timer = 0;
vector<pair<int, int> > bridges;
int n, m;

void dfs(int v, int p) {
    used[v] = true;
    tin[v] = timer;
    low[v] = timer;
    timer++;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p)
            continue;
        if (used[to]) {
            low[v] = min(low[v], tin[to]);  // an edge up
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back(make_pair(v, to));  // no way up from to
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

    for (int v = 0; v < n; v++)
        if (!used[v])
            dfs(v, -1);

    cout << bridges.size() << endl;
    for (size_t i = 0; i < bridges.size(); i++)
        cout << bridges[i].first << " " << bridges[i].second << endl;
    return 0;
}
