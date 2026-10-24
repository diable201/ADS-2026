# Lecture 8 — Rabin–Karp and String Hashing

Every file is standalone and compiles with:

    g++ -std=c++17 -O2 -o out file.cpp && ./out

The examples use polynomial rolling hashes with base `29` and unsigned
64-bit arithmetic.

| File | Topic | What it is |
|------|-------|------------|
| `01_string_hash.cpp` | String hashing | Compute and print a polynomial hash for each input string |
| `02_equal_strings.cpp` | Hash groups | Group strings by hash and print pairs of equal strings after verifying their contents |
| `03_rabin_karp.cpp` | Rabin–Karp | Find every occurrence of a pattern in a text using polynomial prefix hashes |
| `04_distinct_substrings.cpp` | Distinct substrings | Count distinct substrings by inserting normalized substring hashes into a set |

Input and output:

- `01_string_hash.cpp` reads `n` and then `n` strings, printing each string
  with its hash.
- `02_equal_strings.cpp` reads `n` strings and prints the indices of every
  pair containing equal strings.
- `03_rabin_karp.cpp` reads a text and a pattern, then prints the starting
  indices where the pattern occurs in the text.
- `04_distinct_substrings.cpp` reads one string and prints the number of
  distinct substrings.

The Rabin–Karp example compares the pattern hash with normalized substring
hashes instead of comparing every substring character by character. As with
any single-hash approach, hash collisions are theoretically possible.
