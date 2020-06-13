#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
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

void Open(const string & name, set<string> & st) {
	int i;
	ifstream fin(name);
	string t;
	rep(i, 50) {
		fin >> t;
		st.insert(t);
	}
	return;
}

int main(void) {
	int num, i, a, b;
	ll ans = 0;
	set<string> s;
	Open("0079_input.txt", s);
	vector<map<int, int>> pa(10), ch(10);
	for (auto it = s.begin(); it != s.end(); it++) {
		rep(i, 2) {
			a = (*it)[i] - '0', b = (*it)[i + 1] - '0';
			ch[a][b]++;
			pa[b][a]++;
		}
	}
	while (true) {
		rep(i, 10) {
			cout << i << "\n";
			//cout << ch[i].size() << "   child num\n";
			cout << pa[i].size() << "   parent num\n\n";
		}
		cout << ans << "\n";
		printf("remove = ");
		cin >> a;
		if (a >= 10)
			break;
		ans *= 10;
		ans += a;
		rep(i, 10) {
			if (pa[i].count(a)) {
				pa[i].erase(a);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
