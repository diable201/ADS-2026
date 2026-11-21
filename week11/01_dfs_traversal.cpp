#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];
bool used[100000];
int n, m;

void dfs(int v) {
    used[v] = true;
    cout << v << " ";
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to);
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
    int s;
    cin >> s;
    dfs(s);
    cout << endl;
    return 0;
}