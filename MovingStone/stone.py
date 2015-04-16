while True:
    # Read input
    n = input()
    if n < 0:
        break

    a = []
    while len(a) < n:
        a.extend(map(int, raw_input().split()))

    # total = number of stones
    total = sum(a)

    # res = our final result
    res = 0
    if total % n > 0:
        res = -1
    else:
        each = total / n  # How many stones each box have at final
        l = 0
        r = 0

        for i in xrange(n):
            a[i] += r - l

            if a[i] > each:
                # If a[i] > each, we must move stones to our right
                l = 0
                r = a[i] - each
            else:
                # Otherwise, we must borrow from our right
                l = each - a[i]
                r = 0

            # Update result
            res = max(res, max(l, r))

    raw_input()
    print res
