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
#define LIM 50000000ll - 1

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Eratos(vector<char> & p) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

// n以下の要素の中で最大の添え字を返す
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(ll n, vector<ll>& d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	ll num, i, j, k, ans = 0, bc;
	vector<char> d(10000, 1);
	vector<ll> a, b, c;
	set<int> s;
	Eratos(d);
	rep(i, d.size()) {
		if (d[i]) {
			a.push_back(i * i);
			b.push_back(*a.rbegin() * i);
			c.push_back(*b.rbegin() * i);
		}
	}
	rep(i, b.size()) {
		rep(j, c.size()) {
			bc = b[i] + c[j];
			if (a[0] + bc >= LIM)
				break;
			rep(k, Binary_search(LIM - bc, a) + 1) {
				s.insert(a[k] + bc);
			}
		}
	}
	cout << s.size() << "\n";
	return 0;
}
