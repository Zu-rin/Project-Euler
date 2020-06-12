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
typedef pair<int, int> pp;

void Input(const string name, vector<vector<int>> & d) {
	int i, j;
	ifstream fin(name);
	for (i = 1; i <= 100; i++) {
		d.push_back(vector<int>(i));
		rep(j, i)
			fin >> d[i - 1][j];
	}
	return;
}

int main(void) {
	int num, i, j;
	vector<vector<int>> d;
	Input("0067_input.txt", d);
	for (i = d.size() - 1; i > 0; i--) {
		rep(j, d[i].size() - 1)
			d[i - 1][j] += max(d[i][j], d[i][j + 1]);
	}
	cout << d[0][0] << "\n";
	return 0;
}
