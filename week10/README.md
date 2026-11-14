# Lecture 10 — Graph Representations and BFS

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

Graphs use zero-based vertex numbering. Unless noted otherwise, the input
starts with `n m`, followed by `m` undirected edges.

| File | Topic | What it is |
|------|-------|------------|
| `01_adjacency_matrix.cpp` | Adjacency matrix | Build and print a matrix representation of an undirected graph |
| `02_adjacency_list.cpp` | Adjacency list | Build and print an unweighted adjacency list |
| `03_weighted_adjacency_list.cpp` | Weighted graph | Build and print an adjacency list containing neighbor-weight pairs |
| `04_bfs_distances.cpp` | BFS distances | Traverse from a source vertex and print visit order and shortest edge distances |
| `05_bfs_path.cpp` | BFS path reconstruction | Find and print a shortest path between two vertices |
| `06_connected_components.cpp` | Connected components | Count connected components with BFS |
| `07_bipartite_graph.cpp` | Bipartite graph | Check whether an undirected graph can be colored with two colors |

## Examples

### `01_adjacency_matrix.cpp`

Input:

    3 2
    0 1
    1 2

Output:

    0 1 0
    1 0 1
    0 1 0

### `02_adjacency_list.cpp`

Input:

    3 2
    0 1
    1 2

Output:

    0: 1
    1: 0 2
    2: 1

### `03_weighted_adjacency_list.cpp`

Input:

    3 2
    0 1 5
    1 2 7

Output:

    0: (1, 5)
    1: (0, 5) (2, 7)
    2: (1, 7)

### `04_bfs_distances.cpp`

Input:

    4 3
    0 1
    1 2
    1 3
    0

Output:

    0 1 2 3
    0 1 2 2

### `05_bfs_path.cpp`

Input:

    4 3
    0 1
    1 2
    2 3
    0 3

Output:

    0 1 2 3

### `06_connected_components.cpp`

Input:

    5 2
    0 1
    3 4

Output:

    3

### `07_bipartite_graph.cpp`

Input:

    4 4
    0 1
    1 2
    2 3
    3 0

Output:

    YES
