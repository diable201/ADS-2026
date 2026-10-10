# Lecture 6 — Sorting Algorithms

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

Each program reads `n` followed by `n` integers from standard input and prints
the sorted array on one line.

| File | Topic | What it is |
|------|-------|------------|
| `01_bubble_sort.cpp` | Bubble sort | Repeatedly swap adjacent elements that are out of order; stop early when a pass makes no swaps |
| `02_quick_sort_two_pointers.cpp` | Quicksort | Partition around the middle value using two pointers, then recursively sort both parts |
| `03_quick_sort_lomuto.cpp` | Quicksort | Lomuto partition scheme with the last element as the pivot |
| `04_std_sort.cpp` | STL sorting | Sort the input with `std::sort` |
| `05_heap_sort.cpp` | Heapsort | Build a max-heap and repeatedly move its maximum to the end of the array |

For example:

    echo "6 5 1 4 2 8 3" | ./out

All implementations sort in ascending order. Bubble sort and the two
quicksort implementations are included to compare different sorting
strategies, while `std::sort` provides the standard-library solution.
