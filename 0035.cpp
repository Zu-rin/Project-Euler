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

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Eratos(vector<int> & d, set<int> &st) {
	int i, j;
	d[0] = d[1] = 0;
	for (i = 2; i < d.size(); i++) {
		if (d[i]) {
			st.insert(i);
			for (j = i << 1; j < d.size(); j += i)
				d[j] = 0;
		}
	}
	return;
}

int Judge(int n, vector<int> &p, set<int> &st) {
	int i, num, a, ans = n;
	set<int> ok;
	string s = to_string(n);
	num = s.size();
	s += s;
	st.erase(n);
	ok.insert(n);
	for (i = 1; i < num; i++) {
		a = stoi(s.substr(i, num));
		if (p[a] && a >= n) {
			if (!ok.count(a)) {
				ans += a;
				ok.insert(a);
			}
			st.erase(a);
		}
		else
			return 0;
	}
	return ok.size();
}

int main(void) {
	int num, i, a;
	ll ans = 0;
	vector<int> p(1000000, 1);
	set<int> st;
	Eratos(p, st);
	while (!st.empty()) {
		ans += Judge(*st.begin(), p, st);
	}
	cout << ans << "\n";
	return 0;
}
