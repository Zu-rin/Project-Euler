#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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

const int c[10] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };
int Change(int n) {
	int ans = n / 1000, b = n;
	n %= 1000;
	while (n > 0) {
		ans += c[n % 10];
		n /= 10;
	}
	return ans;
}

int Change(const string& s, map<char, int> &mp) {
	int i, n = 0;
	rep(i, s.size() - 1) {
		if (mp[s[i]] < mp[s[i + 1]])
			n -= mp[s[i]];
		else
			n += mp[s[i]];
	}
	n += mp[s[i]];
	return Change(n);
}

int main(void) {
	int num = 1000, i, ans = 0, sum = 0;
	string s;
	map<char, int> mp;
	ifstream fin("0089_input.txt");
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;
	rep(i, num) {
		fin >> s;
		sum += s.size();
		ans += Change(s, mp);
	}
	cout << ans << "\n";
	return 0;
}