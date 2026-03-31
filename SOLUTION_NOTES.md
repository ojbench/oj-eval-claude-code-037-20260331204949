# Problem 037 - Doubly Linked List Solution

## Final Score: 100/100

## Submission Summary
- **Submission ID**: 766205
- **Status**: Accepted
- **Score**: 100.0 (All 10 test points passed)
- **Memory Usage**: 3.98 MB (max)
- **Time Usage**: 12 ms (total across all test points)

## Implementation Details

### Data Structure
Implemented a doubly linked list with sentinel nodes (dummy head and tail) to simplify edge cases.

### Operations Implemented
1. **Get_length()** - Returns the current length of the list
2. **insert(i, x)** - Inserts value x at position i (0-indexed)
3. **Query(i)** - Returns value at position i, or -1 if out of bounds
4. **remove(i)** - Removes node at position i
5. **Print()** - Prints all elements, or -1 if empty
6. **Clear()** - Deallocates all nodes to prevent memory leaks

### Key Design Decisions
- Used sentinel nodes (head/tail) to avoid null pointer checks
- Maintained a length counter for O(1) length queries
- Helper function `move(i)` to traverse to position i

### Test Results
All 10 test points passed with:
- No memory leaks
- Fast execution (1-2 ms per test point)
- Minimal memory usage (~4 MB)

## Submission History
1. **Submission 766200**: Compile Error (Makefile was in .gitignore)
2. **Submission 766205**: Accepted (100/100)

Total valid submissions used: 1 of 5
