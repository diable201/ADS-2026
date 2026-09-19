# Lecture 3 — Binary Search · code from the slides

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

| File | Slides | What it is |
|------|--------|------------|
| `01_linear_search.cpp` | 04 | The O(n) baseline, no preconditions |
| `02_binary_search_exact.cpp` | 07–09 | Classic template, `while (l <= r)`, plus size 0/1/2 cases |
| `03_cf_queries.cpp` | 11 | Codeforces EDU problem A — n sorted numbers, k queries, YES/NO |
| `04_nearest_elements.cpp` | 14–16 | The `l + 1 < r` template: nearest ≤ x and nearest > x, plus lower bound by hand |
| `05_stl_bounds.cpp` | 18–19 | `lower_bound` / `upper_bound` / `binary_search` and the six counting questions |
| `06_min_square.cpp` | 23–25 | Answer search, integer: smallest square side for n tiles |
| `07_max_rope.cpp` | 26–29 | Answer search, real: n ropes into k equal pieces, fixed 100 iterations |
| `08_traps.cpp` | 09, 17 | Overflow, the infinite loop, and an unsorted array failing silently |

Expected output is written as a comment next to every call.

Two templates, never mixed:

- `while (l <= r)` — inclusive `[l, r]`, both moves step **past** mid (`mid ± 1`).
- `while (l + 1 < r)` — `l` and `r` mark a border, `mid` **becomes** the new marker (no ±1).
  `l` is the last position where the condition holds, `r` the first where it fails.

`03_cf_queries.cpp` reads from stdin; `07_max_rope.cpp` reads from stdin and falls back to
the lecture example (4 ropes, 11 pieces → 200.50) when there is no input. The rest run as is.
