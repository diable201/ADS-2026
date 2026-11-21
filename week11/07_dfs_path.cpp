#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];
bool used[100000];
vector<int> path;
int n, m, t;

bool dfs(int v) {
    used[v] = true;
    path.push_back(v);
    if (v == t)
        return true;  // found: path holds the way from s to t
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to] && dfs(to))
            return true;
    }
    path.pop_back();  // dead end: v is not on the way
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
    int s;
    cin >> s >> t;

    if (dfs(s)) {
        for (size_t i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << endl;
    } else {
        cout << "NO PATH" << endl;
    }
    return 0;
}
