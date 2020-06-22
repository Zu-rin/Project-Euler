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
	ll ans = 0;
	vector<vector<ll>> dp(101, vector<ll>(101, 0));
	for (i = 1; i <= 100; i++) {
		dp[i][1] = 1;
		for (j = 2; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[max(i - j, 0)][j];
	}
	for (i = 2; i <= 100; i++)
		ans += (ll)dp[100][i];
	cout << ans << "\n";
	return 0;
}
