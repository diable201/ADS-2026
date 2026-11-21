#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];
bool used[100000];
int n, m;

bool dfs(int v, int p) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) {
            continue; // the edge we came by
        }
        if (used[to]) {
            return true; // a visited vertex, not the parent: cycle
        }
        if (dfs(to, v)) {
            return true;
        }
    }
    return false;
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
        if (!used[v] && dfs(v, -1)) {
            cout << "CYCLE" << endl;
            return 0;
        }
    }
    cout << "NO CYCLE" << endl;
    return 0;
}