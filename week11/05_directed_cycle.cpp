#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];
bool used[100000];
bool inPath[100000]; // the vertex is on the current path
int n, m;

bool dfs(int v) {
    used[v] = true;
    inPath[v] = true;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (inPath[to]) {
            return true; // en edge back in the current path: cycle
        }
        if (!used[to] && dfs(to)) {
            return true;
        }
    }
    inPath[v] = false; // we leave v
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); // directed: one line only
    }
    for (int v = 0; v < n; v++) {
        if (!used[v] && dfs(v)) {
            cout << "CYCLE" << endl;
            return 0;
        }
    }
    cout << "NO CYCLE" << endl;
    return 0;
}