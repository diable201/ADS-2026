#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100000];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int v = 0; v < n; v++) {
        cout << v << ":";
        for (size_t i = 0; i < g[v].size(); i++) {
            cout << " " << g[v][i];
        }
        cout << endl;
    }
    return 0;
}