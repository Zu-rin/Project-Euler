#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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

ll Score(string s) {
	int i;
	ll ans = s.size();
	rep(i, s.size()) {
		ans += s[i] - 'A';
	}
	return ans;
}

int main(void) {
	int num, i;
	ll p = 1, ans = 0;
	string s, name;
	map<string, ll> mp;
	ifstream f("0022_input.txt");
	getline(f, s);
	rep(i, s.size()) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			name = "";
			while (s[i] != '"') {
				name += s[i++];
			}
			mp[name] = Score(name);
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans += p * (*it).second;
		p++;
	}
	cout << ans << "\n";
	return 0;
}
