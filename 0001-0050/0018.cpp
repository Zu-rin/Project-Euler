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

int Search(int n, int dep, vector<int> &d) {
	if (dep == 15)
		return d[n];
	return d[n] + max(Search(n + dep, dep + 1, d), Search(n + dep + 1, dep + 1, d));
}

int main(void) {
	int num, i;
	vector<int> d(15 * 8);
	rep(i, d.size())
		cin >> d[i];
	cout << Search(0, 1, d) << "\n";
	return 0;
}
