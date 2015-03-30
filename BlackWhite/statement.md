# Statement

On the Oxy plane, there is a square of size 1000, with 4 vertices at 4 points: (0, 0), (0, 1000), (1000, 0) and (1000, 1000). We color the regions inside the square like below:

![Illustration](./Figure1.png)

Consider a rectangle with opposite corners at (X1, Y1) and (X2, Y2). Obviously, this rectangle lies completely inside our given square.

Count the number of 2*2 squares within this rectangle that contains 2 black cells and 2 white cells. For example, the rectangle with opposite corners (2, 3) and (7, 6) (marked with dash-line in the above figure) contains 6 squares with 2 black and 2 white cells.

# Constraints:

- 0 <= X1, Y1, X2, Y2 <= 1000.

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
