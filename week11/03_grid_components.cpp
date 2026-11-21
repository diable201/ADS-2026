#include <iostream>
#include <vector>

using namespace std;

int a[100][100];
bool used[100][100];
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    used[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (a[nx][ny] == 1 && !used[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && !used[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}