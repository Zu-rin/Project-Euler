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

ll nC2(ll n) {
	return n * (n - 1) / 2;
}

int main(void) {
	int dif = INF, i, j, ans;
	ll a, tag = 2000000;
	rep(i, 100) {
		rep(j, i) {
			a = nC2(i * j) - nC2(i) * j - nC2(j) * i;
			a >>= 1;
			if (dif > abs(tag - a)) {
				dif = abs(tag - a);
				ans = (i - 1) * (j - 1);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
