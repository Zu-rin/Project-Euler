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

int Judge(int n) {
	string s, t;
	while (n > 0) {
		if (n & 1)
			s += "1";
		else
			s += "0";
		n >>= 1;
	}
	t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int main(void) {
	int num, i;
	ll ans = 0;
	for (i = 1; i < 1000000; i++) {
		string s, t;
		s = t = to_string(i);
		reverse(t.begin(), t.end());
		if (s == t && Judge(i))
			ans += i;
	}
	cout << ans << "\n";
	return 0;
}
