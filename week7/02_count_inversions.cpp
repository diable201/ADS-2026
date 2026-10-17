#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    long long cnt = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            cnt += n1 - i;
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    return cnt;
}

long long countInversions(vector<int>& a, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    long long leftCount = countInversions(a, left, mid);
    long long rightCount = countInversions(a, mid + 1, right);
    long long crossCount = mergeAndCount(a, left, mid, right);
    return leftCount + rightCount + crossCount;
}

int main() {
    int n;

    if (!(cin >> n) || n < 0) {
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << countInversions(a, 0, n - 1) << '\n';
    return 0;
}