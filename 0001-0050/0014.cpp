#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Search(int n, vector<int> & d) {
	if (n >= d.size()) {
		if (n & 1)
			return Search(3 * n + 1, d) + 1;
		return Search(n >> 1, d) + 1;
	}
	if (d[n])
		return d[n];
	if (n & 1)
		return Search(3 * n + 1, d) + 1;
	return Search(n >> 1, d) + 1;
}

int main(void) {
	ll num, i, n, ans, ma = 0, a;
	vector<int> d(1000000, 0);
	d[1] = 1;
	for (i = 1; i < d.size(); i++) {
		a = 0;
		n = i;
		while (n > 0) {
			if (n < d.size() && d[n]) {
				a += d[n];
				break;
			}
			if (n & 1)
				n = 3 * n + 1;
			else
				n >>= 1;
			a++;
		}
		if (ma < a) {
			ma = a;
			ans = i;
		}
		d[i] = a;
	}
	cout << ans << "\n";
	return 0;
}
