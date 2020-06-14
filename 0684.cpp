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
	ll ans = 1, a = n % MOD;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ans;
}

ll Inverse(ll a) {
	return Pow(a, MOD - 2);
}

ll Sum(ll n) {
	ll a = n / 9, b = n % 9, ans = 0, p;
	ans += 6 * (Pow(10, a) - 1) - 9 * a;
	ans %= MOD;
	ans += MOD;
	ans += (b * (b + 3) / 2) * Pow(10, a) - b;
	ans %= MOD;
	return ans;
}

int main(void) {
	int num, i;
	ll ans = 0;
	//ans = Sum(20);
	vector<ll> fib(91, 0);
	fib[1] = 1;
	rep(i, 89)
		fib[i + 2] = fib[i + 1] + fib[i];
	for(i = 2; i <= 90; i++) {
		ans += Sum(fib[i]);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}
