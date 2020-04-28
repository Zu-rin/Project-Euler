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
	int num = 0, i, j;
	vector<int> d(10000000, 1);
	d[0] = d[1] = 0;
	for (i = 2; i < d.size(); i++) {
		if (d[i]) {
			for (j = i << 1; j < d.size(); j += i)
				d[j] = 0;
		}
	}
	rep(i, d.size()) {
		if (d[i]) {
			num++;
			if (num == 10001)
				break;
		}
	}
	cout << i << "\n";
	return 0;
}