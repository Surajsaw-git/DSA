# DSA_A2Z

A C++ practice repository for learning data structures, algorithms, recursion, patterns, and basic problem-solving.

This repository contains small standalone programs. Most files can be compiled and run independently with a C++ compiler.

## Repository Structure

```text
DSA_A2Z/
|-- CPP/          # Basic C++ and array practice programs
|-- DAA/          # Design and Analysis of Algorithms examples
|-- Pattern/      # Star pattern programs
|-- Recursion/    # Recursion practice
|-- Graph/        # Placeholder for graph problems
`-- Tree/         # Placeholder for tree problems
```

## Topics Covered

### CPP

Beginner C++ problem-solving examples:

| File | Topic |
| --- | --- |
| `Code1.cpp` | Find the maximum element in an array |
| `Code2.cpp` | Reverse an array using an extra array |
| `Code2A.cpp` | Reverse an array in-place using two pointers |
| `Code3.cpp` | Move zeroes to the end by shifting elements |
| `Code3A.cpp` | Move zeroes to the end using an optimized approach |
| `Code4.cpp` - `Code23.cpp` | Empty practice files reserved for future problems |

### DAA

Algorithm examples:

| File | Topic |
| --- | --- |
| `Binary_search.cpp` | Binary search on a sorted array |
| `fact.cpp` | Iterative factorial |
| `fact_R.cpp` | Recursive factorial |
| `fab.cpp` | Iterative Fibonacci series |
| `fab_R.cpp` | Recursive Fibonacci series |
| `quick_sort.cpp` | Quick sort with execution time measurement |

### Pattern

Star pattern programs:

| File | Topic |
| --- | --- |
| `code.cpp` | Right-angled triangle star pattern |
| `code1.c++` | Square star pattern |
| `code2.cpp` | Pattern class example |

### Recursion

| File | Topic |
| --- | --- |
| `fyCode.cpp` | Basic recursive function practice |

## Requirements

- C++ compiler such as `g++`
- Terminal or VS Code

## Compile and Run

From the repository root, compile any source file with `g++`.

### Windows PowerShell

```powershell
g++ .\DAA\quick_sort.cpp -o .\DAA\quick_sort.exe
.\DAA\quick_sort.exe
```

### Linux or macOS

```bash
g++ ./DAA/quick_sort.cpp -o ./DAA/quick_sort
./DAA/quick_sort
```

You can replace `DAA/quick_sort.cpp` with any other `.cpp` or `.c++` file in the repository.

## Notes

- The repository currently includes some generated files such as `.exe`, `.o`, `build/`, `output/`, and `output.txt`.
- The `.gitignore` file is set up to ignore generated build artifacts and editor/system files going forward.
- Source files are intentionally left unchanged.
