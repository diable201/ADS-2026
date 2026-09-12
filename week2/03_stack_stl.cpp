// 3. Stack — std::stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(15);
    st.push(1);

    cout << st.top() << endl;        // 1
    st.pop();
    st.pop();
    cout << st.top() << endl;        // 20
    cout << st.size() << endl;       // 2
    cout << st.empty() << endl;      // 0

    // pop() returns void: read with top(), then remove with pop()
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;                    // 20 10
    return 0;
}
