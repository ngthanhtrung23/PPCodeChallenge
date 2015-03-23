# Statement

You are given a square with size 1000. The square is put on the Oxy plane, such that one of its corner is at (0, 0), and the edges of the square are along Ox and Oy axes.

![Illustration](./Figure1.png)

Consider a rectangle with opposite corners: (X1, Y1) and (X2, Y2). (0 <= X1, Y1, X2, Y2 <= 1000). Obviously, this rectangle lies completely inside our given square.

Count the number of 2*2 squares within this rectangle that contains 2 black cells and 2 white cells.

# Input
- 1st line: T - number of test cases.
- Next T lines: each line contains X1, Y1, X2, Y2

# Output
- For each test case, print the result

# Example
## Input
```
1
2 3 7 6
```

## Output
```
6
```
