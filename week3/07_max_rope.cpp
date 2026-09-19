//   check(len) = sum of floor(rope / len) >= k   monotone the OTHER way: T T T F F F
//   we want the LAST true  ->  return l
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool canCut(const vector<double>& ropes, double len, int k) {
    long long count = 0;                       // long long: short pieces from long ropes
    for (double r : ropes)
        count += (long long)(r / len);
    return count >= k;
}

double maxRopeLength(vector<double>& ropes, int k) {
    double l = 0, r = *max_element(ropes.begin(), ropes.end());   // tight, obvious bound

    for (int iter = 0; iter < 100; iter++) {   // fixed count: while(r-l > eps) can hang
        double mid = (l + r) / 2;              // mid > 0 always, so no division by zero
        if (canCut(ropes, mid, k)) l = mid;
        else                       r = mid;
    }
    return l;                                  // l is the side we verified
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) {                    // no input -> run the lecture example
        vector<double> demo = {802, 743, 457, 539};
        cout << fixed << setprecision(2) << maxRopeLength(demo, 11) << "\n";  // 200.50
        cout << fixed << setprecision(2) << maxRopeLength(demo, 12) << "\n";  // 185.75
        return 0;                              // note: 2541/11 = 231 would give only 9 pieces
    }

    vector<double> ropes(n);
    for (int i = 0; i < n; i++) cin >> ropes[i];

    cout << fixed << setprecision(2) << maxRopeLength(ropes, k) << "\n";
    return 0;
}
// sample input:
// 4 11
// 802
// 743
// 457
// 539
// sample output:
// 200.50
