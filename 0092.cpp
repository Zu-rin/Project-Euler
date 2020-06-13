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

int Next(int n) {
	int ans = 0;
	while (n > 0) {
		ans += (n % 10) * (n % 10);
		n /= 10;
	}
	return ans;
}

int Fill(int n, vector<int>& d) {
	if (d[n])
		return d[n];
	return d[n] = Fill(Next(n), d);
}

int main(void) {
	int num = 10000000, i, ans = 0;
	vector<int> d(num << 1, 0);
	d[1] = 1;
	d[89] = 89;
	for (i = 2; i < num; i++)
		Fill(i, d);
	rep(i, num) {
		if (d[i] == 89)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
