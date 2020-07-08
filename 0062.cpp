#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
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

int main(void) {
	ll num = 1e6, i;
	string s;
	map<string, pp> mp;
	rep(i, num) {
		s = to_string(i * i * i);
		sort(s.begin(), s.end());
		if (++mp[s].first == 5)
			break;
		if (!mp[s].second)
			mp[s].second = i;
	}
	i = mp[s].second;
	cout << i * i * i << "\n";
	return 0;
}
