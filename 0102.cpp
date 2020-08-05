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
	int x, y;
	friend Point_Coordinates operator-(Point_Coordinates& l, Point_Coordinates& r) {
		return { l.x - r.x, l.y - r.y };
	}
} point;

char Judge(point a, point b) {
	return a.x * b.y - a.y * b.x > 0;
}

int main(void) {
	int num = 1000, i, j, ans = 0;
	vector<vector<point>> d(num, vector<point>(3));
	ifstream fin("0102_input.txt");
	rep(i, num) {
		rep(j, 3)
			fin >> d[i][j].x >> d[i][j].y;
	}
	rep(i, num) {
		auto a = Judge(d[i][0], d[i][1]);
		if (a == Judge(d[i][1], d[i][2]) && a == Judge(d[i][2], d[i][0]))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
