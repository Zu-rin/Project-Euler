#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <fstream>
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

void Open(const string & name, vector<int> & d) {
	int i, a = 0;
	ifstream fin(name);
	string s;
	fin >> s;
	rep(i, s.size()) {
		if (s[i] == ',') {
			d.push_back(a);
			a = 0;
		}
		else {
			a *= 10;
			a += s[i] - '0';
		}
	}
	d.push_back(a);
	return;
}

int Show(int n, string & t) {
	string s = "a";
	s[0] += n - 'a';
	t += s;
	if (('A' <= s[0] && s[0] <= 'Z') || ('a' <= s[0] && s[0] <= 'z') || ('0' <= s[0] && s[0] <= '9') || s[0] == ' ')
		return 0;
	return 1;
}

int main(void) {
	int num, i, j, k, s = 'a', e = 'z', ans = 0;
	vector<int> d;
	Open("0059_input.txt", d);
	/*for (i = s; i <= e; i++) {
		for (j = 120; j <= 120; j++) {
			for (k = 112; k <= 112; k++) {
				string t = "";
				for (int x = 0; x < d.size(); x += 3) {
					int ng = Show(d[x] ^ i, t);
					ng |= Show(d[x + 1] ^ j, t);
					ng |= Show(d[x + 2] ^ k, t);
				}
				if (t.size() > 3) {
					printf("i,j,k = ");
					cout << i << " ";
					cout << j << " ";
					cout << k << "\n";
					cout << t << "\n";
				}
			}
		}
	}*/
	int x = 0, a[3] = { 101,120,112 };
	while (x < d.size()) {
		rep(i, 3)
			ans += d[x++] ^ a[i];
	}
	cout << ans << "\n";
	return 0;
}
