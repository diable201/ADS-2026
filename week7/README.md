# Lecture 7 — Merge Sort and Inversions

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

| File | Topic | What it is |
|------|-------|------------|
| `01_merge_sort.cpp` | Merge sort | Recursively split an array, sort both halves, and merge them into ascending order |
| `02_count_inversions.cpp` | Inversion counting | Count pairs `(i, j)` where `i < j` and `a[i] > a[j]` using merge sort in `O(n log n)` time |

Both programs read `n` followed by `n` integers from standard input.

`01_merge_sort.cpp` prints the sorted array on one line:

    echo "6 5 1 4 2 8 3" | ./out

`02_count_inversions.cpp` prints the number of inversions. The count uses
`long long` because an array can contain more inversions than fit in a regular
`int`.
