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

int Search(int n, vector<char> & d, vector<int> & k) {
	if (d[n])
		return d[n];
	d[n] = 1;
	int a = 0, b = n;
	while (b) {
		a += k[b % 10];
		b /= 10;
	}
	return d[n] = Search(a, d, k) + 1;
}

int main(void) {
	int num = 1e6, i, ans = 0;
	vector<char> d(3 * num, 0);
	vector<int> k(10, 1);
	for(i = 1; i < 10; i++)
		k[i] = k[i - 1] * i;
	rep(i, num)
		Search(i, d, k);
	rep(i, num) {
		if (d[i] == 61)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
