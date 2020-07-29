#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <tuple>
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

int Search(const tuple<int, int, int> t, set<tuple<int, int, int>> & st) {
	if (st.count(t))
		return 0;
	st.insert(t);
	int g, a = get<1>(t) - get<2>(t) * get<2>(t), b, c;
	g = gcd(a, get<0>(t));
	a /= g;
	g = get<0>(t) / g;
	b = get<1>(t) * g * g;
	c = -get<2>(t) * g;
	c -= ((int)sqrt(b) + c) / a * a;
	return Search(tuple<int, int, int>(a, b, c), st) + 1;
}

int main(void) {
	int num = 1e4, i, ans = 0;
	rep(i, num + 1) {
		int s = sqrt(i);
		if (s * s < i) {
			set<tuple<int, int, int>> st;
			if (Search(tuple<int, int, int>(1, i, -s), st) & 1)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
