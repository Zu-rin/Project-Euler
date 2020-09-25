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

ll Pow(ll n, ll k) {
	ll ans = 1, a = n;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
		}
		a *= a;
		k >>= 1;
	}
	return ans;
}

int Judge(ll n, vector<int> &d) {
	ll a = 0, b = n;
	while (n > 0) {
		a += d[n % 10];
		n /= 10;
	}
	return a == b;
}

int main(void) {
	int num = 400000, i;
	ll ans = 0;
	vector<int> d(10);
	rep(i, 10)
		d[i] = Pow(i, 5);
	for (i = 2; i < num; i++) {
		if (Judge(i, d))
			ans += i;
	}
	cout << ans << "\n";
	return 0;
}
