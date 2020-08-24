#include <iostream>
#include <fstream>
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
typedef struct Point {
	int i, j;
	friend Point operator+(const Point& l, const Point& r) {
		return { l.i + r.i, l.j + r.j };
	}
	friend bool operator<(const Point& l, const Point& r) {
		return l.i < r.i;
	}
	friend bool operator>(const Point& l, const Point& r) {
		return !(l.i < r.i);
	}
} point;
typedef pair<int, point> pp;

void Input(vector<vector<int>> & d) {
	int i, j;
	ifstream fin("0083_input.txt");
	for (i = 1; i <= 80; i++) {
		for (j = 1; j <= 80; j++)
			fin >> d[i][j];
	}
	return;
}

int Dijkstra(vector<vector<int>>& d) {
	int i;
	point dn[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
	vector<vector<int>> ans(82, vector<int>(82, INF));
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(d[1][1], { 1, 1 }));
	while (!que.empty()) {
		int c = que.top().first;
		point n = que.top().second;
		que.pop();
		if (ans[n.i][n.j] == INF) {
			ans[n.i][n.j] = c;
			rep(i, 4) {
				point x = n + dn[i];
				if (ans[x.i][x.j] == INF && d[x.i][x.j] != INF)
					que.push(pp(c + d[x.i][x.j], x));
			}
		}
	}
	return ans[80][80];
}

int main(void) {
	int num, i;
	vector<vector<int>> d(82, vector<int>(82, INF));
	Input(d);
	cout << Dijkstra(d) << "\n";
	return 0;
}
