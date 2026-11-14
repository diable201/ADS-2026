#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > g[100000]; // {neighbor, weight}
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    }

    for (int v = 0; v < n; v++) {
        cout << v << ":";
        for (size_t i = 0; i < g[v].size(); i++) {
            cout << " (" << g[v][i].first << ", " << g[v][i].second << ")";
        }
        cout << endl;
    }
    return 0;
}