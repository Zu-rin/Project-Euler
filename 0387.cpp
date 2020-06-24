#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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

void Add_Harshad(const pair<ll, int> & n, map<ll, int> &mp) {
	int i;
	rep(i, 10) {
		int a = n.second + i;
		if ((n.first * 10 + i) % a == 0)
			mp[n.first * 10 + i] = a;
	}
	return;
}

int Is_prime(ll n) {
	if (n != 2 && !(n & 1))
		return 0;
	if (n == 1)
		return 0;
	for (ll i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

ll Sum_strong(ll n, int a) {
	if (!Is_prime(n / a))
		return 0;
	ll i, ans = 0;
	for (i = 1; i < 10; i += 2) {
		if (Is_prime(10L * n + i))
			ans += 10L * n + i;
	}
	return ans;
}

int main(void) {
	ll num = 1e12, i, ans = 0;
	map<ll, int> mp;
	rep(i, 10)
		mp[i] = i;
	for(auto it = ++mp.begin(); it != mp.end(); it++){
		if ((*it).first >= num)
			break;
		Add_Harshad(*it, mp);
	}
	for (auto it = ++mp.begin(); it != mp.end(); it++) {
		ans += Sum_strong((*it).first, (*it).second);
	}
	cout << ans << "\n";
	return 0;
}
