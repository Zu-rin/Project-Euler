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
	int num, i, j, ans = 0;
	vector<int> d = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3 };
	d.resize(1001);
	d[11] = d[12] = 6;
	d[13] = d[14] = d[18] = d[19] = 8;
	d[15] = d[16] = 7;
	d[17] = 9;
	d[20] = d[30] = d[80] = d[90] = 6;
	d[40] = d[50] = d[60] = 5;
	d[70] = 7;
	d[1000] = 11;
	for (i = 2; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			d[10 * i + j] = d[10 * i] + d[j];
		}
	}
	for (i = 100; i < 1000; i++) {
		if (i % 100 == 0)
			d[i] = d[i / 100] + 7;
		else {
			d[i] = d[i / 100 * 100] + d[i % 100] + 3;
		}
	}
	for (i = 1; i < d.size(); i++)
		ans += d[i];
	cout << ans << "\n";
	return 0;
}
