// Author: Do Ngoc Khanh
#include<iostream>
using namespace std;

const int N = 1000;
long long f[4*N+1], g[2*N+1];
int n, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n; for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			++g[a[i] + a[j]];
	for(int i = 1; i <= (n << 1); ++i)
		for(int j = 1; j <= (n << 1); ++j)
			f[i+j] += g[i] * g[j];
	for(int i = 1; i <= (n << 2); ++i)
		cout << f[i] << ' ';
	cout << "\n";
	return 0;
}
