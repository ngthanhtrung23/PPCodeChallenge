// Complexity: O(1)
#include <algorithm>
#include <iostream>
using namespace std;

// Count the number of 2*2 squares inside the rectangle with 2 vertices:
// (0, 0) and (x, y)
long long f(long long x, long long y) {
    return max(0LL, (x - 1) * (y - 1) - min(x, y) + 1);
}

int main() {
    // Read number of test
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Handle traps: x1 > x2, y1 > y2
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        ++x1; ++y1;
        cout << max(0LL, f(x2, y2) - f(x1, y2) - f(x2, y1) + f(x1, y1)) << "\n";
    }
    return 0;
}
