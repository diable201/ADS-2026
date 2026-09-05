#include <iostream>

using namespace std;

long long binpow(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        long long half = binpow(a, n / 2);
        return half * half;
    } else {
        return a * binpow(a, n - 1);
    }
}

long long binpow_iter(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= a;
        }
        a *= a;
        n /= 2;
    }
    return result;
}

int main() {
    long long base, exp;
    cin >> base >> exp;
    cout << binpow(base, exp) << endl;
    return 0;
}