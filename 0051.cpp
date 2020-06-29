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

void Eratos(vector<char>& p) {
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

char Is_prime(int n, vector<char>& p) {
	return p[n];
}

int MakeFam(const string & s, const vector<char> & p) {
	char x = '0';
	int i, j, num = 10, ans = INF;
	rep(i, 10) {
		string t = "0" + s;
		rep(j, t.size()) {
			if (t[j] == '0')
				t[j] = x + i;
		}
		if (!p[stoi(t)]) {
			num--;
			if (num < 8)
				return 0;
		}
		else
			chmin(ans, stoi(t));
	}
	return ans;
}

int main(void) {
	int num = 1e7, i, ans;
	vector<char> p(num + 1, 1);
	Eratos(p);
	for (i = 11; i < p.size(); i += 2) {
		if (ans = MakeFam(to_string(i), p)) {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
