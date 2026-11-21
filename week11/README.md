# Lecture 11 — Depth-First Search

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

Graphs use zero-based vertex numbering unless stated otherwise.

| File | Topic | What it is |
|------|-------|------------|
| `01_dfs_traversal.cpp` | DFS traversal | Visit and print every reachable vertex from a source |
| `02_connected_components.cpp` | Components | Assign component numbers to an undirected graph |
| `03_grid_components.cpp` | Grid components | Count components of adjacent cells containing `1` |
| `04_undirected_cycle.cpp` | Undirected cycle | Detect a cycle using DFS and the parent edge |
| `05_directed_cycle.cpp` | Directed cycle | Detect a back edge in a directed graph |
| `06_topological_sort.cpp` | Topological sort | Print a valid vertex order for a directed acyclic graph |
| `07_dfs_path.cpp` | DFS path | Find a path between two vertices and print it |
| `08_strongly_connected_components.cpp` | Strongly connected components | Count SCCs and assign a component to every vertex |
| `09_bridges.cpp` | Bridges | Find undirected edges whose removal disconnects the graph |

## Examples

### `01_dfs_traversal.cpp`

Input:

    5 5
    0 1
    0 2
    1 3
    2 3
    3 4
    0

Output:

    0 1 3 2 4

### `02_connected_components.cpp`

Input:

    5 3
    0 1
    1 2
    3 4

Output:

    2
    1 1 1 2 2

### `03_grid_components.cpp`

Input:

    3 3
    1 1 0
    0 1 0
    0 0 1

Output:

    2

### `04_undirected_cycle.cpp`

Input:

    3 3
    0 1
    1 2
    2 0

Output:

    CYCLE

### `05_directed_cycle.cpp`

Input:

    3 3
    0 1
    1 2
    2 0

Output:

    CYCLE

### `06_topological_sort.cpp`

Input:

    4 3
    0 1
    0 2
    1 3

Output:

    0 2 1 3

### `07_dfs_path.cpp`

Input:

    5 4
    0 1
    1 2
    2 3
    3 4
    0 4

Output:

    0 1 2 3 4

### `08_strongly_connected_components.cpp`

Input:

    5 5
    0 1
    1 0
    1 2
    2 3
    3 2

Output:

    3
    2 2 3 3 1

### `09_bridges.cpp`

Input:

    4 3
    0 1
    1 2
    2 3

Output:

    3
    2 3
    1 2
    0 1
