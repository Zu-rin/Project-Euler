#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

void Eratos(vector<int> & p, vector<ll> & d) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			d.push_back(i);
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int Judge(ll n, vector<int> & p) {
	if (n < p.size())
		return p[n];
	else
		return 0;
}

// n以下の要素の中で最大の添え字を返す
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(ll n, vector<ll>& d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num = 1000000, i, j, k, m;
	ll ans = 0, a = 0;
	vector<int> p(num, 1);
	vector<ll> d{ 0 };
	Eratos(p, d);
	rep(i, d.size() - 1)
		d[i + 1] += d[i];
	m = Binary_search(num, d);
	for (k = m; k > 0; k--) {
		rep(i, d.size()) {
			j = i + k;
			if (j >= d.size())
				break;
			if (Judge(d[j] - d[i], p)) {
				cout << d[j] - d[i] << "\n";
				return 0;
			}
		}
	}
	return 0;
}
