#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 10000000000ll
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Pow(ll n, ll k) {
	ll ans = 1, i;
	rep(i, k) {
		ans *= n;
		ans %= MOD;
	}
	return ans;
}

int main(void) {
	int num;
	ll ans = 0, i;
	for (i = 1; i <= 1000; i++) {
		ans += Pow(i, i);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}