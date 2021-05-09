#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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

int Search(ll n, string & s, vector<vector<ll>> &mp, int f = 0, ll sum = 0) {
	if (f == s.size()) {
		if (sum == n)
			return 1;
		return 0;
	}
	if (n < sum)
		return 0;
	for (int l = 1; f + l <= s.size(); l++) {
		ll sub = mp[f][l] ? mp[f][l] : mp[f][l] = stoll(s.substr(f, l));
		if (Search(n, s, mp, f + l, sum + sub))
			return 1;
	}
	return 0;
}

int main(void) {
	ll i = 2, lim = 1e6, ans = 0, log = 50000;
	while (i <= lim) {
		if (i == log) {
			cout << i << "\n";
			log += 50000;
		}
		string s = to_string(i * i);
		vector<vector<ll>> c(s.size(), vector<ll>(s.size(), 0));
		if (Search(i, s, c))
			ans += i * i;
		i++;
	}
	cout << ans << "\n";
	return 0;
}