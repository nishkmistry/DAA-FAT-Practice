# Copilot Instructions for DAA-FAT-Practice

## Repository Overview

This is a **Design and Analysis of Algorithms (DAA) - First Assessment Test (FAT)** practice repository containing C++ implementations of classic algorithms across three categories:

1. **Karatsuba** - Fast multiplication algorithm for large numbers (O(n^1.585) vs O(n²))
2. **Lowest Common Subsequence (LCS)** - Dynamic programming approach to find longest matching subsequences
3. **Maximum Sum Subarray** - Divide-and-conquer approach to find contiguous subarray with maximum sum

Each algorithm category has 3 implementations exploring different approaches or optimizations.

## Build and Execution

### Compile
```bash
g++ -o <output_name> <filename>.cpp
```

### Run
```bash
./<output_name>.exe          # Windows
./<output_name>              # Linux/Mac
```

### Run Single Test Example
```bash
cd Karatsuba
g++ -o test karatsuba_code1.cpp
./test.exe
# Select: 1 for automated tests, 2 for manual input
```

## Code Conventions

### Structure Pattern
- **Single file per implementation** - Each `.cpp` file is standalone with no external dependencies
- **Direct I/O** - Programs use `cin`/`cout` for user interaction (no stdin redirection expected)
- **Minimal headers** - Only necessary includes: `iostream`, `string`, `algorithm`, `vector`, `climits`
- **Namespace** - All code uses `using namespace std;`

### Algorithm Implementation Pattern
```cpp
#include<necessary_headers>
using namespace std;

// Core algorithm function (often short names like k(), lcs(), etc.)
return_type algorithm_name(parameters) {
    // Implementation
}

// Optional: helper functions, structs for return values

int main() {
    // User input handling
    // Call algorithm
    // Display results
    return 0;
}
```

### Naming Conventions
- **Short function names** - `k()` for Karatsuba, `lcs()` for Longest Common Subsequence
- **Compact variable names** - `x, y, m, n, l, r, h` for indices, boundaries, and loop counters
- **Result structs** - Use structs to bundle multiple return values (e.g., `SubarrayData {sum, start, end}`)

## Algorithm-Specific Details

### Karatsuba Multiplication
- **Time Complexity**: O(n^1.585) vs standard O(n²)
- **Base case**: Numbers < 10 use standard multiplication
- **Algorithm**: Divide-and-conquer—splits numbers at midpoint, combines via 3 recursive calls
- **Location**: `Karatsuba/` directory
- **Special feature** (karatsuba_code1.cpp): Includes automated test suite validating against standard `*` operator

### Lowest Common Subsequence (LCS)
- **Algorithm**: Dynamic programming with 2D DP table `l[m+1][n+1]`
- **Outputs**: Both LCS length and the actual substring
- **Location**: `LowestCommonSubsequence/` directory
- **Variants**: Three implementations exploring different DP construction approaches

### Maximum Sum Subarray
- **Algorithm**: Divide-and-conquer recursively finding max in left, right, and crossing subarrays
- **Outputs**: Maximum sum with start and end indices via `SubarrayData` struct
- **Location**: `MaximumSumSubarray/` directory
- **Variants**: Three implementations exploring different recursive strategies

## Testing

- **Manual testing**: Each program prompts for user input during execution
- **Automated validation**: Karatsuba includes built-in test suite (karatsuba_code1.cpp)
- **Verification approach**: Compare algorithm output against standard operations
- **Multiple implementations**: Each algorithm has 3 versions for comparing different approaches

## Common Tasks

### Test a single algorithm
```bash
cd <Algorithm>
g++ -o output filename.cpp
./output.exe
# Follow prompts for input
```

### Add test case to Karatsuba
Edit the `testCases` vector in the `runTests()` function in `karatsuba_code1.cpp`.

### Improve an implementation
- Maintain single-file structure for standalone compilation/execution
- Keep I/O in `main()` for interactive testing
- Update or add test cases if modifying algorithm logic
- Compile with `g++` to verify before committing
