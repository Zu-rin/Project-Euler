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

string Tostr(vector<int> & d) {
	int i, s, p;
	string ans = "";
	for (i = 6, s = 5; i < 10; i++) {
		if (d[s] > d[i])
			s = i;
	}
	rep(i, 5) {
		p = (s + i) % 5;
		ans += to_string(d[p + 5]) + to_string(d[p]) + to_string(d[(p + 1) % 5]);
	}
	return ans;
}

string Judge(vector<int> & d) {
	int i, a = d[0] + d[4] + d[9];
	rep(i, 4) {
		if (d[i] == 10 || d[i] + d[i + 1] + d[i + 5] != a)
			return "0";
	}
	if (d[4] == 10)
		return  "0";
	return Tostr(d);
}

int main(void) {
	int num, i;
	string ans = "0", a;
	vector<int> d(10);
	rep(i, d.size())
		d[i] = i + 1;
	while (next_permutation(d.begin(), d.end())) {
		a = Judge(d);
		if (ans < a) {
			cout << a << "\n";
			ans = a;
		}
	}
	cout << ans << "\n";
	return 0;
}
