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

int CombiOver(ll n, ll k) {
	ll i, ans = 1;
	for (i = 1; i <= k; i++) {
		ans *= n--;
		ans /= i;
	}
	if (ans > 1000000)
		return true;
	return 0;
}

int main(void) {
	int num, i, j, ans = 0;
	for (i = 10; i <= 100; i++) {
		rep(j, i >> 1) {
			if (CombiOver(i, j)) {
				ans += i - j - j + 1;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
