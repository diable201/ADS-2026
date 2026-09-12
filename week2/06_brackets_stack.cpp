// 6. Balanced brackets — stack, works for () [] {}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_ok(string s) {
    stack<char> st;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (st.empty())                        return false;
            if (s[i] == ')' && st.top() != '(')    return false;
            if (s[i] == ']' && st.top() != '[')    return false;
            if (s[i] == '}' && st.top() != '{')    return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;
    if (is_ok(s)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}
