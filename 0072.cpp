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

ll Euler(ll n, const list<int> & d) {
	for (auto it = d.begin(); it != d.end(); it++) {
		n /= *it;
		n *= *it - 1;
	}
	return n;
}

int main(void) {
	int num = 1e6 + 1, i, j;
	ll ans = 0;
	vector<list<int>> d(num);
	for(i = 2; i < num; i++) {
		if (!d[i].size()) {
			for (j = i; j < num; j += i) {
				d[j].push_back(i);
			}
		}
		ans += Euler(i, d[i]);
	}
	cout << ans << "\n";
	return 0;
}
