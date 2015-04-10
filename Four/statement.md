# Problem

Given an array A with N elements. The i-th element is denoted by A_i.

Find the number of ways to select 4 elements, such that the sum of the 4 selected elements is K. You can select each element more than once.

For example:

```
A = [1, 2, 3, 4, 5, 6]
```

For K = 5, you have 4 different ways:

- Select 1, 1, 1, 2
- Select 1, 1, 2, 1
- Select 1, 2, 1, 1
- Select 2, 1, 1, 1

For K = 6, you have 10 different ways:

- 1, 1, 1, 3
- 1, 1, 2, 2
- 1, 1, 3, 1
- 1, 2, 1, 2
- 1, 2, 2, 1
- 1, 3, 1, 1
- 2, 1, 1, 2
- 2, 1, 2, 1
- 2, 2, 1, 1
- 3, 1, 1, 1

# Constraints:

- 1 <= N <= 1000.
- 1 <= A_i <= 1000.

# Input:

- The first line contains the only number N
- The second line contains N integers, representing the array A.

# Output:

- Contains 4*N integers, the i-th integer is the result for K = i.

# Example:
## Input
```
6
1 2 3 4 5 6
```

## Output
```
0 0 0 1 4 10 20 35 56 80 104 125 140 146 140 125 104 80 56 35 20 10 4 1
```
