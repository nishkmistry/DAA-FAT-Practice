# Copilot Instructions for DAA-FAT-Practice

## Repository Overview

This is a **Design and Analysis of Algorithms (DAA) - First Assessment Test (FAT)** practice repository containing C++ implementations of classic algorithms across three categories:

1. **Karatsuba** - Fast multiplication algorithm for large numbers
2. **Lowest Common Subsequence (LCS)** - Dynamic programming string matching
3. **Maximum Sum Subarray** - Divide-and-conquer approach to find maximum subarray

Each algorithm category has multiple implementations (typically 3 variants) exploring different approaches or optimizations.

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

### Example: Karatsuba with Self-Tests
```bash
cd Karatsuba
g++ -o karatsuba_code1 karatsuba_code1.cpp
./karatsuba_code1.exe
# Then choose: 1 for automated tests, 2 for manual input
```

## Code Conventions

### Structure Pattern
- **Single file per implementation** - Each `.cpp` file is standalone
- **Direct I/O** - Programs use `cin`/`cout` for user interaction (no stdin redirection expected)
- **Minimal headers** - Only necessary includes (algorithm, iostream, string, vector, climits)
- **Namespace** - All code uses `using namespace std;`

### Algorithm Pattern
All implementations follow this structure:
```cpp
#include<necessary_headers>
using namespace std;

// Core algorithm function
return_type algorithm_name(parameters) {
    // Implementation
}

// Optional: helper functions or structs

int main() {
    // User input
    // Call algorithm
    // Display results
    return 0;
}
```

### Naming Conventions
- **Short function names** - Often single letters (e.g., `k()` for Karatsuba, `lcs()` for Longest Common Subsequence)
- **Compact variable names** - `x, y, m, n, l, r, h` for indices and boundaries
- **Result structs** - Structs bundle multiple return values (e.g., `SubarrayData` contains sum, start, end)

## Algorithm-Specific Details

### Karatsuba (Multiplication)
- **Purpose**: O(n^1.585) multiplication vs standard O(n²)
- **Base case**: Numbers < 10 use standard multiplication
- **Divide-and-conquer**: Splits numbers at midpoint, combines via 3 recursive calls
- **Feature** (karatsuba_code1): Includes automated test suite validating against standard multiplication

### Lowest Common Subsequence (LCS)
- **Purpose**: Find longest matching subsequence in two strings
- **DP table**: 2D vector `l[m+1][n+1]` stores LCS lengths
- **Output**: Both LCS length and the actual substring
- **Variants**: Implementations explore different DP construction approaches

### Maximum Sum Subarray
- **Purpose**: Find contiguous subarray with maximum sum (tracks indices)
- **Divide-and-conquer**: Recursively finds max in left, right, and crossing subarrays
- **Helper struct**: `SubarrayData` returns {sum, start_index, end_index}
- **Variants**: Explore different recursive strategies and optimizations

## Testing Strategy

- **Manual input testing** - Each program prompts for user input
- **Automated validation** - Karatsuba includes self-test suite (10 test cases)
- **Comparison verification** - Manual mode compares algorithm output against standard operations
- **Multiple implementations** - Each algorithm has 3 versions for comparing approaches

## Common Tasks

### To test a single algorithm:
1. Navigate to the algorithm directory
2. Compile: `g++ -o output filename.cpp`
3. Run: `./output.exe` and follow prompts

### To add a new test case to Karatsuba:
Edit `runTests()` function in `karatsuba_code1.cpp` - add to the `testCases` vector.

### To improve an implementation:
- Maintain the single-file structure
- Keep I/O in main() for standalone testing
- Update or add test cases if modifying algorithm logic
