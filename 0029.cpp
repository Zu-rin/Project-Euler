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
#define MODa 1000000007
#define MODb 998244353
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;

ll Pow(ll n, ll k, ll MOD) {
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

pp MakeKey(ll n, ll k) {
	pp ans;
	ans.first = Pow(n, k, MODa);
	ans.second = Pow(n, k, MODb);
	return ans;
}

int main(void) {
	int a, b;
	set<pp> s;
	for (a = 2; a <= 100; a++) {
		for (b = 2; b <= 100; b++) {
			s.insert(MakeKey(a, b));
		}
	}
	cout << s.size() << "\n";
	return 0;
}
