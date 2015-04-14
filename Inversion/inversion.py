from array import array

n = input()
MAXV = 50111
BLOCK = 777

ind = array('l', [])
for i in xrange(n+5):
    ind.append(0)
start = array('l', [])
last = array('l', [])
block_len = array('l', [])
sl = []
for i in xrange(411):
    start.append(0)
    last.append(0)
    block_len.append(0)

    tmp = array('l', [])
    for j in xrange(MAXV):
        tmp.append(0)
    sl.append(tmp)


def update(x, u, k):
    v = u
    while v <= MAXV:
        sl[x][v] += k
        v += v & (-v)


def get(x, u):
    res = 0
    v = u
    while v > 0:
        res += sl[x][v]
        v -= v & (-v)
    return res


a = array('l', [0] + map(int, raw_input().split()))
all_values = set(a)
value_map = {}
cnt = 0
for x in all_values:
    cnt += 1
    value_map[x] = cnt
for i in xrange(1, n+1):
    a[i] = value_map[a[i]]

res = 0

for i in xrange(n, 0, -1):
    update(0, a[i], 1)
    res += get(0, a[i] - 1)

nblock = 1
c = 0
for i in xrange(1, n+1, 1):
    if c == 0:
        start[nblock] = i
    ind[i] = nblock
    block_len[nblock] += 1
    c += 1
    if c == BLOCK:
        last[nblock] = i
        nblock += 1
        c = 0

last[nblock] = n
for i in xrange(1, n+1):
    update(ind[i], a[i], 1)

q = input()
for qq in xrange(q):
    u, val = map(int, raw_input().split())
    p = ind[u]

    # Block before u
    for i in xrange(1, p):
        res -= block_len[i] - get(i, a[u])
        res += block_len[i] - get(i, val)

    # Block after u
    for i in xrange(p+1, nblock+1):
        res -= get(i, a[u] - 1)
        res += get(i, val - 1)

    # Block containing u
    for i in xrange(start[p], u):
        if a[i] > a[u]:
            res -= 1
        if a[i] > val:
            res += 1

    for i in xrange(u+1, last[p]+1):
        if a[i] < a[u]:
            res -= 1
        if a[i] < val:
            res += 1

    # Update block containing u
    update(p, a[u], -1)
    a[u] = val
    update(p, val, +1)

    print res
