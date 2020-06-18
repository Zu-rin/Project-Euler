#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 4503599627370517ll
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i = 0, j, ok = true;
	ll ans, l, r;
	l = r = ans = 1504170715041707ll;
	while (l > 0) {
		ll n = (l + r) % MOD;
		if (n < l) {
			ans += n;
			l = n;
			cout << n << "\n";
		}
		else
			r = n;
	}
	cout << ans << "\n";
	return 0;
}
