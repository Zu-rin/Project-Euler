#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

int Sumdiv(int n) {
	int i, s = sqrt(n), ans = 0;
	for (i = 1; i <= s; i++) {
		if (n % i == 0) {
			ans += i + n / i;
			if (i == n / i)
				ans -= i;
		}
	}
	return ans;
}

int main(void) {
	int num, i, x, ok;
	ll ans = 0;
	list<int> d;
	map<int, int> mp;
	for (i = 12; i < 28124; i++) {
		if ((i << 1) < Sumdiv(i))
			d.push_back(i);
	}
	for (auto a = d.begin(); a != d.end(); a++) {
		for (auto b = a; b != d.end(); b++) {
			mp[*a + *b];
		}
	}
	for (i = 1; i < 28124; i++) {
		if (!mp.count(i))
			ans += i;
	}
	cout << ans << "\n";
	return 0;
}