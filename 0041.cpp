#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

int Judge(int n) {
	if (!(n & 1))
		return 0;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int dnum(vector<int>& d) {
	int i, ans = 0;
	rep(i, d.size()) {
		ans *= 10;
		ans += d[i];
	}
	return ans;
}

int main(void) {
	int num, i, ans;
	vector<int> d{ 7,6,5,4,3,2,1 };
	while (true) {
		ans = dnum(d);
		if (Judge(ans))
			break;
		prev_permutation(d.begin(), d.end());
	}
	cout << ans << "\n";
	return 0;
}
