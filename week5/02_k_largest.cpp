#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : a) {
        if (minHeap.size() < k) {
            minHeap.push(x);
        }
        else if (x > minHeap.top()) {
            minHeap.pop();
            minHeap.push(x);
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}