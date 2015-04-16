#include<iostream>
using namespace std;

const int N = 1000;
long long f[4*N+1], g[2*N+1];
int n, a[N];

int main() {
	ios::sync_with_stdio(false);
    // Read input
	cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // g(v) = number of pair (i, j) such that a(i) + a(j) = v
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			++g[a[i] + a[j]];

    // f(v) = number of quad (i, j, k, l) such that a(i) + a(j) + a(k) + a(l) = v
	for(int i = 1; i <= (n << 1); ++i)
		for(int j = 1; j <= (n << 1); ++j) {
            // We have g(i) ways to choose first 2 numbers
            // and g(j) ways to choose the other 2 numbers
			f[i+j] += g[i] * g[j];
        }

    // Print result
	for(int i = 1; i <= (n << 2); ++i)
		cout << f[i] << ' ';
	cout << "\n";
	return 0;
}
