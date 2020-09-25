#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

ll Sumpd(ll n, vector<ll> &d) {
	if (n <= 1)
		return 0;
	if (d[n])
		return d[n];
	ll i, ans = 1, a = sqrt(n);
	if (a * a == n) {
		ans += a;
		a--;
	}
	for (i = 2; i <= a; i++) {
		if (n % i == 0)
			ans += n / i + i;
	}
	return ans;
}

int main(void) {
	ll i, ans = 0, num = 10000;
	vector<ll> d(num, 0);
	rep(i, num) {
		d[i] = Sumpd(i, d);
		if (d[i] < num) {
			d[d[i]] = Sumpd(d[i], d);
			if (i < d[i] && i == d[d[i]]) {
				cout << i << " " << d[i] << "\n";
				ans += i + d[i];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
