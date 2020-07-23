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

char IsPermutation(ll a, ll b) {
	string s = to_string(a), t = to_string(b);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

double Euler(ll n, const list<int> & d) {
	ll ans = n;
	for (auto it = d.begin(); it != d.end(); it++) {
		ans /= *it;
		ans *= *it - 1;
	}
	if (IsPermutation(n, ans)) {
		return (double)n / (double)ans;
	}
	return 2.0;
}

int main(void) {
	int num = 1e7, i, ans;
	double r = 2.0, e;
	vector<list<int>> d(num);
	for (i = 2; i < num; i++) {
		if (!d[i].size()) {
			for (int j = i; j < num; j += i)
				d[j].push_back(i);
		}
		e = Euler(i, d[i]);
		if (r > e) {
			r = e;
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}
