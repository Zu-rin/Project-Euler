#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Judge(int n) {
	double x = (1.0 + sqrt(1.0 + 24.0 * (double)n)) / 6.0;
	return ceil(x) == floor(x);
}

int main(void) {
	int i, j;
	ll ans = INF;
	vector<ll> d(5000);
	set<ll> st;
	for(i = 1; i < d.size(); i++) {
		d[i] = i * (3 * i - 1) / 2;
		st.insert(d[i]);
		for (j = i - 1; j > 0; j--) {
			if (Judge(d[i] + d[j]) && st.count(d[i] - d[j])) {
				chmin(ans, d[i] - d[j]);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
