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
	int num, i, j, k, ans = 0, sum;
	vector<vector<int>> d(20, vector<int>(20));
	rep(i, 20) {
		rep(j, 20) {
			cin >> d[i][j];
			if (d[i][j] == 0)
				d[i][j] = -1;
		}
		sum = 1;
		queue<int> que;
		rep(j, 20) {
			if (que.size() >= 4) {
				sum /= que.front();
				que.pop();
			}
			sum *= d[i][j];
			que.push(d[i][j]);
			chmax(ans, sum);
		}
	}
	rep(j, 20) {
		sum = 1;
		queue<int> que;
		rep(i, 20) {
			if (que.size() >= 4) {
				sum /= que.front();
				que.pop();
			}
			sum *= d[i][j];
			que.push(d[i][j]);
			chmax(ans, sum);
		}
	}
	rep(i, 17) {
		rep(j, 17) {
			sum = 1;
			rep(k, 4)
				sum *= d[i + k][j + k];
			chmax(ans, sum);
		}
	}
	rep(i, 17) {
		for (j = 3; j < 20; j++) {
			sum = 1;
			rep(k, 4)
				sum *= d[i + k][j - k];
			chmax(ans, sum);
		}
	}
	cout << ans << "\n";
	return 0;
}