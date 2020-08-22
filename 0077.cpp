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

void Eratos(vector<char> & p) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int main(void) {
	int num = 300, i, j, k, sum;
	vector<char> p(num, 1);
	vector<vector<int>> dp(num >> 1, vector<int>(num, 0));
	Eratos(p);
	for (i = 2; i < num; i++) {
		if (p[i]) {
			dp[0][i] = 1;
			rep(j, dp.size() - 1) {
				rep(k, num - i) {
					dp[j + 1][k + i] += dp[j][k];
				}
			}
		}
	}
	for (i = 10; i < num; i++) {
		sum = 0;
		rep(j, dp.size())
			sum += dp[j][i];
		if (sum > 5000)
			break;
	}
	cout << i << "\n";
	return 0;
}
