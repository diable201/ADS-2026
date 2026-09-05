#include <iostream>

using namespace std;

vector<int> sieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes = sieve(n);

    for (int prime : primes) {
        cout << prime << " ";
    }
    return 0;
}