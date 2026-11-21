#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> g[100000];
bool used[100000];
vector<int> order;
int n, m;

void dfs(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to);
        }
    }
    order.push_back(v); // v is finished
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); // x must be complete before y
    }
    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            dfs(v);
        }
    }
    reverse(order.begin(), order.end());
    for (size_t i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}