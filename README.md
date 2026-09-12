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
- graph traversal and shortest-path reconstruction.

## License

This project is available under the terms of the [LICENSE](LICENSE) file.
