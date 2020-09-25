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

int Len(int n) {
	int a = 1, b, i = 0;
	map<int, int> mp;
	while (true) {
		b = a % n;
		if (mp.count(b))
			return i + 1 - mp[b];
		mp[b] = i++;
		a = b * 10;
	}
}

int main(void) {
	int num, i, ans = 0;
	for (i = 1; i < 1000; i++) {
		chmax(ans, Len(i));
	}
	cout << ans << "\n";
	return 0;
}