# Lecture 5 — Heaps and Priority Queues

The programs that contain `main` are standalone and can be compiled with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

| File | Topic | What it is |
|------|-------|------------|
| `01_min_heap.cpp` | Min-heap | Insert values into a custom min-heap and output them in ascending order by repeatedly extracting the minimum |
| `02_k_largest.cpp` | Priority queue | Keep the `k` largest values using a min-priority queue of size `k` |
| `03_build_heap.cpp` | Bottom-up heap construction | Build a min-heap from an array with bottom-up heapification and print the resulting heap array |
| `04_max_heap.cpp` | Max-heap | Custom max-heap with insertion, heapification, maximum lookup, and maximum extraction |

`01_min_heap.cpp` reads `n` followed by `n` integers and prints the values
in sorted order.

`02_k_largest.cpp` reads `n`, `k`, and `n` integers. It prints the `k` largest
values in ascending order.

`03_build_heap.cpp` reads `n` followed by `n` integers and prints the internal
array representation of the resulting min-heap.

`04_max_heap.cpp` contains the `MaxHeap` class implementation used to
demonstrate max-heap operations. It does not currently define `main`, so it is
not compiled as a standalone executable.

The heap operations use the standard array representation: for a node at index
`i`, the children are at `2 * i + 1` and `2 * i + 2`.
