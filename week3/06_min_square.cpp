//   check(side) = (side/a) * (side/b) >= n      monotone: F F F T T T
//   we want the FIRST true  ->  return r
#include <iostream>
#include <algorithm>
using namespace std;

bool canFit(long long side, long long a, long long b, long long n) {
    return (side / a) * (side / b) >= n;
}

long long minSquareSide(long long a, long long b, long long n) {
    long long l = 0, r = max(a, b) * n;      // check(0) is false, check(r) is true
                                             // be generous with r: too tight = wrong answer
    while (l + 1 < r) {
        long long mid = l + (r - l) / 2;
        if (canFit(mid, a, b, n)) r = mid;   // invariant: check(l) false, check(r) true
        else                      l = mid;
    }
    return r;
}

int main() {
    cout << minSquareSide(2, 3, 10) << "\n";   // 9   (5 iterations; side 8 gives 4*2=8 < 10)
    cout << minSquareSide(1, 1, 9)  << "\n";   // 3
    cout << minSquareSide(1, 1, 1)  << "\n";   // 1
    cout << minSquareSide(5, 2, 7)  << "\n";   // 10
    return 0;
}
