// 10. Knight's shortest path on an 8x8 board
//     Input:  x1 y1 x2 y2   (1..8)
//     Output: number of moves, then the squares of one shortest path
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a[10][10];                 // 0 = not visited, otherwise = distance + 1
pair<int, int> c[10][10];      // where we came from
queue<pair<int, int> > q;

int dx[8] = {2,  2, -2, -2,  1, 1, -1, -1};
int dy[8] = {1, -1,  1, -1, -2, 2, -2,  2};

bool check(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8 && a[x][y] == 0);
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    a[x1][y1] = 1;
    q.push(make_pair(x1, y1));
    c[x1][y1] = make_pair(x1, y1);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            if (check(x + dx[i], y + dy[i])) {
                a[x + dx[i]][y + dy[i]] = a[x][y] + 1;
                c[x + dx[i]][y + dy[i]] = make_pair(x, y);
                q.push(make_pair(x + dx[i], y + dy[i]));
            }
        }
    }

    cout << a[x2][y2] - 1 << endl;

    vector<pair<int, int> > result;
    result.push_back(make_pair(x2, y2));
    int x = x2, y = y2;
    while (c[x][y] != make_pair(x, y)) {
        int xt = c[x][y].first;
        int yt = c[x][y].second;
        result.push_back(make_pair(xt, yt));
        x = xt;
        y = yt;
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i].first << " " << result[i].second << endl;
    return 0;
}
