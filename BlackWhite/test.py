# Complexity: O(N^2)
ntest = input()
for i in xrange(ntest):
    x1, y1, x2, y2 = map(int, raw_input().split())

    # Handle traps: x1 > x2 and y1 > y2
    if x1 > x2:
        x1, x2 = x2, x1
    if y1 > y2:
        y1, y2 = y2, y1

    res = 0
    for i in xrange(x1, x2-1):
        for j in xrange(y1, y2-1):
            if i != j:
                res += 1
    print res
