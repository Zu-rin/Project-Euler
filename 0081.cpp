#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <fstream>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef struct Point_Coordinates {
	int i, j;
	bool friend operator<(const Point_Coordinates l, const Point_Coordinates r) {
		return l.i < r.i;
	}
} point;
typedef pair<int, point> pp;

void Input(vector<vector<int>> & d) {
	ifstream fin("0081_input.txt");
	int i, j, a;
	string s;
	rep(i, 80) {
		a = 0;
		fin >> s;
		rep(j, s.size()) {
			if (s[j] == ',') {
				d[i].push_back(a);
				a = 0;
			}
			else {
				a *= 10;
				a += s[j] - '0';
			}
		}
		d[i].push_back(a);
	}
	return;
}

int Dijkstra(vector<vector<int>>& d) {
	int i, j, c;
	vector<vector<int>> ans(80, vector<int>(80, INF));
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(d[0][0], { 0, 0 }));
	while (!que.empty()) {
		c = que.top().first;
		point n = que.top().second;
		que.pop();
		if (ans[n.i][n.j] == INF) {
			ans[n.i][n.j] = c;
			if(n.i < 79)
				que.push(pp(c + d[n.i + 1][n.j], { n.i + 1, n.j }));
			if(n.j < 79)
				que.push(pp(c + d[n.i][n.j + 1], { n.i, n.j + 1 }));
		}
	}
	return ans[79][79];
}

int main(void) {
	int num, i;
	vector<vector<int>> d(80);
	Input(d);
	cout << Dijkstra(d) << "\n";
	return 0;
}
