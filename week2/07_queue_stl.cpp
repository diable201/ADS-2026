// 7. Queue — std::queue
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);                          // enqueue at the back
    q.push(20);
    q.push(30);

    cout << q.size()  << endl;           // 3
    cout << q.front() << endl;           // 10
    cout << q.back()  << endl;           // 30

    q.pop();                             // dequeue from the front
    cout << q.front() << endl;           // 20

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;                        // 20 30
    return 0;
}
