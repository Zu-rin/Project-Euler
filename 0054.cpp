#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <fstream>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int IsFrush(vector<string> & a) {
	int i;
	rep(i, 4) {
		if (a[i][1] != a[i + 1][1])
			return 0;
	}
	return 1;
}

int IsStraight(vector<string>& a) {
	int i;
	string s = "23456789JQKA";
	vector<int> d(5);
	rep(i, 5)
		d[i] = s.find(a[i][0]);
	sort(d.begin(), d.end());
	rep(i, 4) {
		if (d[i] + 1 != d[i + 1])
			return 0;
	}
	return 1;
}

int Strength(vector<string> & a) {
	int par, smc, str, frs;

}

int Win1(vector<string> & a, vector<string> & b) {
	int i;


}

int main(void) {
	int num = 1000, i, k, ans = 0;
	vector<string> a(5), b(5);
	ifstream fin("0054_input.txt");
	rep(k, num) {
		rep(i, 5)
			fin >> a[i];
		rep(i, 5)
			fin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (Win1(a, b))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}