// 5. Balanced brackets — counter, works for () only
#include <iostream>
#include <string>
using namespace std;

bool simple_balance(string s) {
    int counter = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            counter++;
        } else if (s[i] == ')') {
            counter--;
            if (counter < 0)        // ')' before any '('
                return false;
        }
    }

    return (counter == 0);          // something left open
}

int main() {
    string s;
    cin >> s;
    if (simple_balance(s)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }       
    cout << endl;
    return 0;
}
