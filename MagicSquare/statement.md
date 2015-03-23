# Problem
A magic square is a square matrix, such that the sum of each row, sum of each column, and sum of 2 diagonals are all the same.

For example:

A magic square:
```
2 9 4
7 5 3
6 1 8
```

Followings are not magic square:
- Sum of row != sum of column:
```
1 1 1
2 2 2
3 3 3
```

- Sum of diagonals != sum of row
```
2 1 1
1 2 1
1 1 2
```

You are given a square matrix, with elements in the main diagonal missing (diagonal with cells (i, i)). Find these elements.

# Input
- 1st line: N
- Next N lines: the matrix. All cells in (i, i) are equal 0 (missing)

# Output
- N lines: the matrix

# Example
## Input
```
3
0 1 1
1 0 1
1 1 0
```

## Output
```
1 1 1
1 1 1
1 1 1
```
