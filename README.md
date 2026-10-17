# Algorithms and Data Structures

This repository contains C++ practice solutions for the Algorithms and Data Structures course at KBTU.

The examples are organized by week and focus on implementing and applying fundamental algorithms and data structures. Each `.cpp` file is a standalone program with its own `main` function.

## Repository Structure

### Week 1: Basic Algorithms

- Greatest common divisor: brute-force, recursive Euclidean algorithm, and iterative Euclidean algorithm
- Binary exponentiation
- Sieve of Eratosthenes
- Prime factorization
- Basic usage of `std::stack`

### Week 2: Data Structures and Graph Traversal

- Node structures and templates
- Stack implementations using the STL and linked nodes
- Bracket sequence processing
- Queue and deque operations
- Breadth-first search for minimum operations
- Shortest path for a knight on an 8x8 chessboard
- A custom doubly linked list with insertion, deletion, and traversal operations

### Week 3: Binary Search and Search on Sorted Arrays

- Linear search and its complexity baseline
- Exact binary search on sorted arrays
- Codeforces-style query checking with sorted data
- Neighborhood search: nearest smaller and greater elements
- STL search tools: `lower_bound`, `upper_bound`, and `binary_search`
- Answer-search tasks for integer and real-valued problems
- Edge cases: overflow, infinite loops, and invalid assumptions

### Week 4: Binary Search Trees and Ordered Containers

- BST insertion, deletion, traversals, height, and counting
- Range queries on binary search trees
- Ordered container usage with `std::set` and `std::multiset`
- Lower/upper bound operations on sorted data
- Comparison between custom tree structures and STL containers

### Week 5: Heaps and Priority Queues

- Min-heap insertion and repeated minimum extraction
- Finding the `k` largest values with a min-priority queue
- Bottom-up construction of a min-heap
- Custom max-heap operations and array-based heap representation

### Week 6: Sorting Algorithms

- Bubble sort with an early-stop optimization
- Quicksort with two-pointer partitioning
- Quicksort with the Lomuto partition scheme
- Heapsort using a max-heap
- Sorting with the standard library's `std::sort`

### Week 7: Merge Sort and Inversions

- Merge sort with recursive divide-and-conquer merging
- Counting array inversions in `O(n log n)` time
- Using merge sort to count cross-half inversions efficiently

## Requirements

- A C++ compiler with C++11 support or newer
- Standard C++ library

The examples can be compiled with `g++` or `clang++`.

## Compile and Run

Compile any source file from the repository:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic week1/1.cpp -o gcd
```

Run the resulting program:

```bash
./gcd
```

Most programs expect input from standard input. For example, `week1/1.cpp` reads two integers and prints their greatest common divisor:

```bash
echo "48 18" | ./gcd
```

Each source file may be compiled separately. The output format and input requirements are documented in the source code where they are not self-explanatory.

## Learning Goals

The exercises demonstrate:

- time and space complexity trade-offs;
- recursive and iterative algorithm design;
- STL containers and their basic operations;
- pointer manipulation and dynamic memory management;
- graph traversal and shortest-path reconstruction;
- efficient searching on sorted data;
- tree-based data structures and ordered sets.

## License

This project is available under the terms of the [LICENSE](LICENSE) file.
