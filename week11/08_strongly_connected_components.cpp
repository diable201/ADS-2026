#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];   // the graph
vector<int> rg[100000];  // the same graph with every edge reversed
bool used[100000];
vector<int> order;
int comp[100000];
int n, m;

void dfs1(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to])
            dfs1(to);
    }
    order.push_back(v);  // v is finished
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (size_t i = 0; i < rg[v].size(); i++) {
        int to = rg[v][i];
        if (comp[to] == 0)
            dfs2(to, c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    // pass 1: finish order in the graph
    for (int v = 0; v < n; v++)
        if (!used[v])
            dfs1(v);

    // pass 2: reversed graph, the last finished vertex first
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        int v = order[i];
        if (comp[v] == 0) {
            cnt++;
            dfs2(v, cnt);
        }
    }

    cout << cnt << endl;
    for (int v = 0; v < n; v++)
        cout << comp[v] << " ";
    cout << endl;
    return 0;
}
