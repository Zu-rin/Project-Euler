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

double nPk(ll n, ll k) {
	ll ans = 1;
	while (k > 0) {
		ans *= n--;
		k--;
	}
	return (double)ans;
}

int main(void) {
	int num, i;
	// 60_C_20 / 70_C_20
	double ans = nPk(50, 10) / nPk(70, 10);
	ans = 7.0 * (1.0 - ans);
	printf("%.9lf\n", ans);
	return 0;
}
