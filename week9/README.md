# Lecture 9 — Prefix Function and KMP

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

The examples use the prefix function to analyze strings and implement
linear-time pattern matching with the Knuth–Morris–Pratt (KMP) algorithm.

| File | Topic | What it is |
|------|-------|------------|
| `01_prefix_function_naive.cpp` | Naive prefix function | Compute prefix-function values by checking candidate borders directly |
| `02_prefix_function.cpp` | Prefix function | Compute the prefix function in linear time by falling back through previously computed values |
| `03_kmp_search.cpp` | KMP search | Find every occurrence of a pattern in a text using the prefix function |
| `04_borders.cpp` | String borders | Print all proper border lengths and the corresponding prefixes |
| `05_string_period.cpp` | String period | Find the shortest repeating unit and its repetition count |
| `06_cyclic_shift.cpp` | Cyclic shift | Check whether the pattern occurs in the text doubled with itself |

Input and output:

- `01_prefix_function_naive.cpp` and `02_prefix_function.cpp` read one
  string and print its prefix-function array.
- `03_kmp_search.cpp` reads a text and a pattern and prints all starting
  positions where the pattern occurs.
- `04_borders.cpp` reads one string and prints its proper borders from longest
  to shortest.
- `05_string_period.cpp` reads one string and prints its shortest period and
  repetition count.
- `06_cyclic_shift.cpp` reads a text and a pattern and prints `YES` if the
  pattern occurs in the doubled text, otherwise `NO`.

## Examples

### `01_prefix_function_naive.cpp` and `02_prefix_function.cpp`

Input:

    ababcabab

Output:

    0 0 1 2 0 1 2 3 4

### `03_kmp_search.cpp`

Input:

    ababa
    ba

Output:

    1 3

### `04_borders.cpp`

Input:

    ababa

Output:

    3 aba
    1 a

### `05_string_period.cpp`

Input:

    abcabcabc

Output:

    abc x 3

### `06_cyclic_shift.cpp`

Input:

    abc
    bca

Output:

    YES
