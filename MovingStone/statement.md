# Problem

Given N box on a straight line. The i-th box has A(i) stones.

For 1 < i < N, the i-th box has 2 neighbours: the (i-1)th box and the (i+1)th box. The 1st box only has 1 neighbour (the 2nd box). The Nth box only has 1 neighbour (the (N-1)th box).

You need to move the stones between boxes, so that the number of stones in each box are equal.

In each move, you can do the following:
- Take one stone from one of the box.
- Add one stone to one of its neighbouring box.

Find the minimum number of moves.

# Input
There are multiple test cases in the input file.
For each test:
- 1st line: N - number of boxes
- 2nd line: N integers - A(i).

# Output
For each test, print 1 line containing the result.

# Example
## Input
```
3
0 99 3

2
49 50

8
16 17 15 0 20 1 1 2

10
0 0 100 0 0 0 0 0 0 0

-1

```
## Output
```
34
-1
23
70
```
