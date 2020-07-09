// this solution need to take 12 seconds
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
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

void Eratos(vector<char> & p, vector<int> & d) {
	int i, j;
	for (i = 3; i < p.size(); i += 2) {
		if (p[i]) {
			d.push_back(i);
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int Diggain(int a, int b) {
	int ans = b;
	while (b) {
		a *= 10;
		b /= 10;
	}
	return ans + a;
}

char IsConnect(int a, int b, vector<char> & p) {
	return p[Diggain(a, b)] & p[Diggain(b, a)];
}

int Search(const set<int> & d, map<int, set<int>> &mp, int n, int dep = 1) {
	if (dep == 5)
		return n;
	if (!d.size())
		return 0;
	int ans = 0;
	for (auto it = d.begin(); it != d.end(); it++) {
		set<int> st;
		set_intersection(d.begin(), d.end(), mp[*it].begin(), mp[*it].end(), inserter(st, st.end()));
		if (ans = Search(st, mp, *it, dep + 1))
			break;
	}
	if (ans)
		return ans + n;
	else
		return 0;
}

int main(void) {
	int num = 1e8, i, j, ans;
	vector<char> p(num, 1);
	vector<int> d;
	map<int, set<int>> mp;
	Eratos(p, d);
	rep(i, d.size() - 1) {
		for (j = i + 1; d[j] < 10000; j++) {
			if (IsConnect(d[i], d[j], p))
				mp[d[i]].insert(d[j]);
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (ans = Search((*it).second, mp, (*it).first))
			break;
	}
	cout << ans << "\n";
	return 0;
}
