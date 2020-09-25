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

void Split(string & s, vector<string> & d) {
	while (true) {
		auto pos = s.rfind(",");
		if (pos < 0 || s.size() <= pos)
			break;
		d.push_back(s.substr(pos + 1));
		s.erase(pos);
	}
	d.push_back(s);
	reverse(d.begin(), d.end());
	return;
}

void Pull(const string& file, vector<string>& d) {
	string s;
	ifstream fin(file);
	fin >> s;
	Split(s, d);
	return;
}

int tonum(string& s) {
	int i, ans = 0;
	for(i = 1; i < s.size() - 1; i++)
		ans += s[i] - 'A' + 1;
	return ans;
}

int main(void) {
	int num, i = 2, k = 1, ans = 0;
	vector<int> d(10000, 0);
	vector<string> s;
	Pull("0042_input.txt", s);
	while (k < 10000) {
		d[k] = 1;
		k += i++;
	}
	rep(i, s.size()) {
		if (d[tonum(s[i])])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
