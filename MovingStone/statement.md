# Problem

Given N box on a straight line. The i-th box has A(i) stones.

For 1 < i < N, the i-th box has 2 neighbours: the (i-1)th box and the (i+1)th box. The 1st box only has 1 neighbour (the 2nd box). The Nth box only has 1 neighbour (the (N-1)th box).

You need to move the stones between boxes, so that the number of stones in each box are equal.

In each move, you can do the following:
- For each box i, you can either do one of the following:
  - Do nothing with this box
  - Take one stone from this box and put that stone in one of its neighbouring box.
  - If this box has 2 neighbours, you can take 2 stones in this box, put one in each of the neighbouring box (you cannot put 2 stones in the same neighbouring box).

Find the minimum number of moves.

# Constraints:
- 1 <= N <= 10,000.
- 1 <= A_i <= 1,000,000,000.

# Input
There are multiple test cases in the input file.
For each test:
- 1st line: N - number of boxes
- 2nd line: N integers - A(i).

The last line of the input file contains the only integer -1.

# Output
For each test:
- If there is no solution, prints -1
- Otherwise, print the minimum number of move.

# Example
## Input
```
3
0 99 3

2
49 50

3
3 0 3

-1

```
## Output
```
34
-1
1
```

## Explanation:
- In the first test, there are 102 stones in total. So after all moves, there must be 34 stones (102 / 3 = 34) in each box.

```
+---+---+---+
| 0 | 99| 3 |
+---+---+---+
```
  - In the first 31 moves, takes 2 stones from the middle box, and put them in the 2 neighbours:

```
+---+---+---+
| 31| 37| 34|
+---+---+---+
```

  - In the next 3 moves, takes 1 stone from the middle box and put it into the left box:

```
+---+---+---+
| 34| 34| 34|
+---+---+---+
```
  - So we need 34 moves in total.
- In the second test, since there are in total 101 stones, we cannot make the 2 boxes having same amount of stone.
- In the third test, initially, we have:

```
+---+---+---+
| 3 | 0 | 3 |
+---+---+---+
```
  - In 1 move, we can move the stone from left box to middle box, and from right box to middle box. After that, we have 2 stone in each box:
```
+---+---+---+
| 2 | 2 | 2 |
+---+---+---+
```
