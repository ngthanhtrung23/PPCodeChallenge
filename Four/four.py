n = input()
a = map(int, raw_input().split())
f = [0 for i in xrange(4011)]
g = [0 for i in xrange(4011)]

for u in a:
    for v in a:
        g[u + v] += 1

for i in xrange(1, (n << 1)+1):
    for j in xrange(1, (n << 1)+1):
        f[i+j] += g[i] * g[j]

print ' '.join(map(str, f[1:(n << 2)+1]))
