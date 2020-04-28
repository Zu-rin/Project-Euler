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

int main(void) {
	int num, i, j;
	ll ans = 0;
	vector<int> d(2000000, 1);
	d[0] = d[1] = 0;
	rep(i, d.size()) {
		if (d[i]) {
			ans += i;
			for (j = i << 1; j < d.size(); j += i) {
				d[j] = 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}