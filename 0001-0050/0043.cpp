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

ll Judge(vector<int> & d) {
	int i, j, a, k, p[7] = { 17,13,11,7,5,3,2 };
	rep(i, 7) {
		a = 0, k = 1;
		rep(j, 3) {
			a += d[i + j] * k;
			k *= 10;
		}
		if (a % p[i])
			return 0;
	}
	ll v = 1, ans = 0;
	rep(i, d.size()) {
		ans += d[i] * v;
		v *= 10;
	}
	return ans;
}

int main(void) {
	int num, i;
	ll ans = 0;
	vector<int> d{ 9,8,7,6,5,4,3,2,0,1 };
	do {
		ans += Judge(d);
	} while (prev_permutation(d.begin(), d.end()));
	cout << ans << "\n";
	return 0;
}
