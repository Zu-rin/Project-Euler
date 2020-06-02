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

int main(void) {
	int num, i, j;
	string ans = "0";
	for (i = 3; i < 10000; i++) {
		string s;
		for (j = i; s.size() < 9; j += i)
			s += to_string(j);
		if (s.size() == 9) {
			string t = s;
			sort(s.begin(), s.end());
			if (s == "123456789")
				chmax(ans, t);
		}
	}
	cout << ans << "\n";
	return 0;
}
