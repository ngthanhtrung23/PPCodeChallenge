# Problem

Given an array A with N elements (N <= 250,000). Let's denote the i-th element by A(i) 1 <= A(i) <= 50,000.

You are asked to process Q queries on the array. For the i-th query, you need to change the value of some element and count the number of inversion of the array.

An inversion of the array is a pair of indices (i, j) that satisfies the following 2 conditions:
- i < j
- A(i) > A(j)

For example:

```
A = [4, 3, 3, 4]
```

We have 2 inversions:
- 1, 2
- 1, 3

# Input
- First line: the integer N
- 2nd line: N integers Ai
- 3rd line: Q
- Next Q lines: X, Y: Change A(X) = Y

# Output
For each query, print the result in 1 line

# Example
## Input
10
2 6 6 4 7 6 3 5 9 1
7
8 8
5 1
5 6
10 5
7 1
10 10
4 6

## Output
17
18
16
13
14
8
6
