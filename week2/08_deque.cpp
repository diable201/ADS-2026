// 8. Deque — both ends
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    d.push_back(10);
    d.push_back(20);
    d.push_front(30);
    d.push_front(40);                    // 40 30 10 20

    cout << d.front() << endl;           // 40
    cout << d.back()  << endl;           // 20
    cout << d[2]      << endl;           // 10
    cout << d.size()  << endl;           // 4

    d.pop_front();
    d.pop_back();                        // 30 10

    for (int i = 0; i < (int)d.size(); i++)
        cout << d[i] << " ";
    cout << endl;                        // 30 10
    return 0;
}
