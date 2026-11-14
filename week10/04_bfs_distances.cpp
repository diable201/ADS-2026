#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[100000];
bool used[100000];
int d[100000];
int n, m;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (size_t i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    cout << endl;
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

    for (int v = 0; v < n; v++) {
        d[v] = -1;
    }
    bfs(s);

    for (int v = 0; v < n; v++) {
        cout << d[v] << " ";
    }
    cout << endl;
    
    return 0;
}