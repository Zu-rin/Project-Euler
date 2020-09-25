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
	int num, i, j, k;
	vector<int> c = { 2, 5, 10, 20, 50, 100 };
	vector<vector<int>> dp(7, vector<int>(201));
	rep(i, 201)
		dp[0][i] = 1;
	rep(i, 6) {
		rep(j, 201)
			dp[i + 1][j] = dp[i][j];
		rep(j, 201) {
			for (k = j + c[i]; k < 201; k += c[i]) {
				dp[i + 1][k] += dp[i][j];
			}
		}
	}
	cout << dp[6][200] + 1 << "\n";
	return 0;
}