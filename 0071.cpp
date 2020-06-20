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
	int num = 1000000, i, d, ans;
	double mi, tag = 3.0 / 7.0, dif;
	mi = tag - 2.0 / 5.0;
	for (i = 9; i <= num; i++) {
		d = 3 * i / 7;
		dif = tag - (double)d / (double)i;
		if (dif != 0.0 && mi > dif) {
			ans = d;
			mi = dif;
		}
	}
	cout << ans << "\n";
	return 0;
}
