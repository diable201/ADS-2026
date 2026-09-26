# Lecture 4 — Binary Search Trees and Ordered Containers

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

| File | Topic | What it is |
|------|-------|------------|
| `01_bst.cpp` | Binary search tree | Insert, search, minimum and maximum, traversals, height, node count, deletion, and cleanup |
| `02_range_query.cpp` | BST range query | Print all values in a closed interval while pruning irrelevant subtrees |
| `03_set.cpp` | Ordered STL containers | `set`, `multiset`, counting, minimum and maximum, `lower_bound`, `upper_bound`, and erase |

The examples use the same nine values to make the traversal and range-query results easy to compare:

```text
8 9 10 12 13 14 15 16 17
```

`01_bst.cpp` demonstrates the main binary search tree operations. Duplicate values are inserted into the left subtree. Deleting a node with two children replaces it with the maximum value from its left subtree.

`02_range_query.cpp` prints values in the inclusive range `[11, 15]` and reports how many nodes were visited. The traversal skips subtrees that cannot contain values from the requested range.

`03_set.cpp` demonstrates that `std::set` stores unique values in sorted order, while `std::multiset` preserves duplicates.

All programs use hard-coded examples and do not read from stdin.