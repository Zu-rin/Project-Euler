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
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, i, j, ans = 0;
	double l = 1.0 / 3.0, r = 1.0 / 2.0, a;
	set<pp> st;
	for (i = 4; i <= 12000; i++) {
		for (j = i >> 1; j > 1; j--) {
			a = (double)j / (double)i;
			if (l < a) {
				int g = gcd(i, j);
				if (g == 1)
					ans++;
			}
			else
				break;
		}
	}
	cout << ans << "\n";
	return 0;
}
