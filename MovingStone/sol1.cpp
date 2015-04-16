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
        // Read input
		for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);

        // tot = total number of stone
		long long tot = accumulate(a, a+n, 0LL);

        // if we can evenly divide the stones between boxes
		if(tot % n == 0) {
            // each = number of stone in each box at the final configuration
			long long each = tot / n, l = 0, r = 0, res = 0;

			for(int i = 0; i < n; ++i) {
				a[i] += r - l;
                // l = number of stones we must borrow from the right
                // r = number of stones we must move to the right
				if(a[i] > each) l = 0, r = a[i] - each;
				else l = each - a[i], r = 0;
                
                // result is maximum value of l and r
				res = max(res, max(l, r));
			}
			printf("%lld\n", res);
		} else printf("-1\n"); // we cannot evenly divide the stones
	}
	return 0;
}
