#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <fstream>
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
typedef struct Point_Coordinates {
	int i, j;
	friend bool operator<(const Point_Coordinates& l, const Point_Coordinates& r) {
		return l.i < r.i;
	}
} point;

int num = 80;

int Dijkstra(const point &s, vector<vector<int>> &d) {
	int i, ans = INF;
	vector<vector<int>> a(num, vector<int>(num, INF));
	priority_queue<pair<int, point>, vector<pair<int, point>>, greater<pair<int, point>>> que;
	que.push(pair<int, point>(d[s.i][s.j], s));

	while (!que.empty()) {
		auto c = que.top().first;
		auto n = que.top().second;
		que.pop();
		if (a[n.i][n.j] == INF) {
			a[n.i][n.j] = c;
			if (n.i > 0 && a[n.i - 1][n.j] == INF)
				que.push(pair<int, point>(c + d[n.i - 1][n.j], { n.i - 1, n.j }));
			if (n.i < 79 && a[n.i + 1][n.j] == INF)
				que.push(pair<int, point>(c + d[n.i + 1][n.j], { n.i + 1, n.j }));
			if (n.j < 79 && a[n.i][n.j + 1] == INF)
				que.push(pair<int, point>(c + d[n.i][n.j + 1], { n.i, n.j + 1 }));
		}
	}
	rep(i, num) {
		chmin(ans, a[i][79]);
	}
	return ans;
}

int main(void) {
	int i, j, ans = INF;
	vector<vector<int>> d(num, vector<int>(num));
	ifstream fin("0082_input.txt");
	rep(i, num) {
		rep(j, num)
			fin >> d[i][j];
	}
	rep(i, num) {
		chmin(ans, Dijkstra({ i, 0 }, d));
	}
	cout << ans << "\n";
	return 0;
}
