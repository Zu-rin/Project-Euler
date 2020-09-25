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
#define INF 1ll << 40

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

char IsSquare(ll n) {
	ll s = sqrt(n);
	return s * s == n;
}

char Judge(ll n, ll d) {
	if (n % d)
		return 0;
	return IsSquare(n / d);
}

int Solve(int d) {
	for (ll i = 2; i < INF; i++) {
		if (Judge(i * i - 1, d))
			return i;
	}
	return INF;
}

int main(void) {
	int i, num = 1000, ans = 0;
	for(i = 2; i <= num; i++) {
		if (IsSquare(i))
			continue;
		chmax(ans, Solve(i));
	}
	cout << ans << "\n";
	return 0;
}