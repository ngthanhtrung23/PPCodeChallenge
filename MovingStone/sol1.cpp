// Author: Do Ngoc Khanh
#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

const int N = 10000;
long long a[N];
int n;

int main() {
	for(int n; scanf("%d", &n) == 1 && n != -1; ) {
		for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		long long tot = accumulate(a, a+n, 0LL);
		if(tot % n == 0) {
			long long each = tot / n, l = 0, r = 0, res = 0;
			for(int i = 0; i < n; ++i) {
				a[i] += r - l;
				if(a[i] > each) l = 0, r = a[i] - each;
				else l = each - a[i], r = 0;
				res = max(res, max(l, r));
			}
			printf("%lld\n", res);
		} else printf("-1\n");
	}
	return 0;
}
