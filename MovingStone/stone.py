while True:
    n = input()
    if n < 0:
        break

    a = []
    while len(a) < n:
        a.extend(map(int, raw_input().split()))
    total = sum(a)
    res = 0

    if total % n > 0:
        res = -1
    else:
        each = total / n
        l = 0
        r = 0

        for i in xrange(n):
            a[i] += r - l
            if a[i] > each:
                l = 0
                r = a[i] - each
            else:
                l = each - a[i]
                r = 0
            res = max(res, max(l, r))

    raw_input()
    print res
