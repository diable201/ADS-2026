// No preconditions at all: works on unsorted data, O(n).
#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int>& a, int x) {
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] == x) return i;
    return -1;
}

int main() {
    vector<int> a = {18, 3, 27, 5, 32, 13, 8, 21, 19};   // deliberately unsorted
    cout << linear_search(a, 13) << "\n";   // 5
    cout << linear_search(a, 20) << "\n";   // -1
    return 0;
}
