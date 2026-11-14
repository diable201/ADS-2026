#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[100000];
bool used[100000];
int n, m;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
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

    int cnt = 0;
    
    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            bfs(v);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}