#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
#include <set>
#include <map>
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

char IsSquare(int n) {
	return sqrt(n) * sqrt(n) == n;
}

void Initmap(vector<map<int, set<int>>>& d) {
	int i, a;
	rep(i, 70) {
		a = i * (3 * i - 2);
		if (1000 <= a && a < 10000)
			d[0][a / 100].insert(a % 100);
	}
	rep(i, 100) {
		a = i * (5 * i - 3) / 2;
		if (1000 <= a && a < 10000)
			d[1][a / 100].insert(a % 100);
	}
	rep(i, 100) {
		a = i * (2 * i - 1);
		if (1000 <= a && a < 10000)
			d[2][a / 100].insert(a % 100);
	}
	rep(i, 100) {
		a = i * (3 * i - 1) / 2;
		if (1000 <= a && a < 10000)
			d[3][a / 100].insert(a % 100);
	}
	rep(i, 100) {
		a = i * i;
		if (1000 <= a && a < 10000)
			d[4][a / 100].insert(a % 100);
	}
	rep(i, 200) {
		a = i * (i + 1) / 2;
		if (1000 <= a && a < 10000)
			d[5][a / 100].insert(a % 100);
	}
}

int Search(const int head, vector<map<int, set<int>>>& d, int key, int dep = 1) {
	if (dep == 6) {
		if (head == key)
			return key * 101;
		return 0;
	}
	if (!d[dep].count(key))
		return 0;
	set<int> st = d[dep][key];
	for (auto it = st.begin(); it != st.end(); it++) {
		if (int a = Search(head, d, *it, dep + 1))
			return key * 101 + a;
	}
	return 0;
}

int main(void) {
	int sum = 0;
	vector<map<int, set<int>>> d(6);
	Initmap(d);
	for (auto it = d[0].begin(); it != d[0].end(); it++) {
		for (auto key = (*it).second.begin(); key != (*it).second.end(); key++) {
			if (sum = Search((*it).first, d, *key, 1))
				cout << sum << "\n";
		}
	}
	return 0;
}