# Grokking the Coding Interview

Solutions and practice implementations for coding interview problems from the
*Grokking the Coding Interview* study path and related exercises. The code in
this repository is written in C++ and is intentionally kept as small,
standalone problem files.

**Current version:** `v0.1.0`

## Versioning

This repository follows Semantic Versioning in the form `vMAJOR.MINOR.PATCH`.
The version describes the state of the collection of solutions, not the
version of an individual problem.

| Change | Version bump | Example |
| --- | --- | --- |
| Improve, fix, or refactor an existing implementation without changing its intended problem interface | PATCH | `v0.1.0` -> `v0.1.1` |
| Add a new problem or a new standalone solution | MINOR | `v0.1.1` -> `v0.2.0` |
| Make a breaking repository-wide change to naming, organization, or documented interfaces | MAJOR | `v0.2.0` -> `v1.0.0` |

For each version bump, update the **Current version** above and create a Git
tag with the same value, such as `v0.1.1`. Keep each release focused on the
problem changes covered by that version.

Use this commit message format for versioned updates:

```text
release: vX.Y.Z - <short summary>
```

The commit message for this initial version is:

```text
release: v0.1.0 - add initial coding interview solutions
```

## Requirements

- A C++ compiler with C++11 support or newer
- The standard C++ library

## Building and running

Most files can be compiled independently. For example:

```bash
g++ -std=c++11 problem-1-balanced-parentheses.cpp -o balanced-parentheses
./balanced-parentheses
```

Some files contain a `Solution` class intended for an online judge and do not
define a `main` function. Those files can be compiled together with a small
driver program or submitted to the corresponding platform after adapting the
class and method signature as needed.

Compiled Windows executables are ignored by Git through the repository's
`.gitignore` file.

## Solutions

| File | Problem or topic |
| --- | --- |
| [find-the-middle-index-in-array-easy.cpp](find-the-middle-index-in-array-easy.cpp) | Find the middle index in an array |
| [maximum-sum-subarray-of-size-k-easy.cpp](maximum-sum-subarray-of-size-k-easy.cpp) | Maximum sum subarray of size `k` |
| [me-solution-reverse-vowels.cpp](me-solution-reverse-vowels.cpp) | Reverse vowels of a string, personal solution |
| [pair-with-target-sum-easy.cpp](pair-with-target-sum-easy.cpp) | Pair with target sum |
| [problem-1-balanced-parentheses.cpp](problem-1-balanced-parentheses.cpp) | Balanced parentheses |
| [problem-3-decimal-to-binary-conversion.cpp](problem-3-decimal-to-binary-conversion.cpp) | Decimal-to-binary conversion |
| [shortest-word-distance-easy.cpp](shortest-word-distance-easy.cpp) | Shortest distance between words |
| [smallest-subarray-with-a-greater-sum-easy.cpp](smallest-subarray-with-a-greater-sum-easy.cpp) | Smallest subarray with a greater sum |
| [solution-reverse-vowels.cpp](solution-reverse-vowels.cpp) | Reverse vowels of a string, alternate solution |
| [solution-smallest-subarray-with-a-greater-sum.cpp](solution-smallest-subarray-with-a-greater-sum.cpp) | Smallest subarray with a greater sum, alternate solution |
| [sqrt-medium.cpp](sqrt-medium.cpp) | Integer square root |
| [squaring-a-sorted-array-easy.cpp](squaring-a-sorted-array-easy.cpp) | Squaring a sorted array |
| [triplet-sum-to-zero-medium.cpp](triplet-sum-to-zero-medium.cpp) | Triplets with sum zero |
| [valid-anagram-easy.cpp](valid-anagram-easy.cpp) | Valid anagram |
| [valid-anagram-easy-unordered-map.cpp](valid-anagram-easy-unordered-map.cpp) | Valid anagram using `unordered_map` |
| [valid-palindrome-easy.cpp](valid-palindrome-easy.cpp) | Valid palindrome |

## Notes

These are learning exercises rather than a polished library. Implementations
may differ in completeness, style, and whether they include executable test
code. Each file should be reviewed and tested independently.
