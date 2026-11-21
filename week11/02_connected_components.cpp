#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];
int comp[100000]; // 0 means not visited yet
int n, m;

void dfs(int v, int c) {
    comp[v] = c;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (comp[to] == 0) {
            dfs(to, c);
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
    int cnt = 0;
    for (int v = 0; v < n; v++) {
        if (comp[v] == 0) {
            cnt++;
            dfs(v, cnt);
        }
    }
    cout << cnt << endl;
    for (int v = 0; v < n; v++) {
        cout << comp[v] << " ";
    }
    cout << endl;
    return 0;
}