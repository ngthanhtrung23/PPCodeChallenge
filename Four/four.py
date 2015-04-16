# Read input
n = input()
a = map(int, raw_input().split())

# g(v) = number of pair (i, j) such that a(i) + a(j) = v
# Initialize an empty list g
g = [0 for i in xrange(4011)]
for u in a:
    for v in a:
        g[u + v] += 1

# f(v) = number of quad (i, j, k, l) such that a(i) + a(j) + a(k) + a(l) = v
f = [0 for i in xrange(4011)]
for i in xrange(1, (n << 1)+1):
    for j in xrange(1, (n << 1)+1):
        f[i+j] += g[i] * g[j]

# Print result
print ' '.join(map(str, f[1:(n << 2)+1]))
