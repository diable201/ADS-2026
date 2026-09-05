#include <iostream>

using namespace std;

void primeFactorization(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n; // remaining prime
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    primeFactorization(num);
    return 0;
}