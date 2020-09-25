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

int Judge(ll n) {
	double x, y;
	x = (1.0 + sqrt(1.0 + 24.0 * (double)n)) / 6.0;
	y = (1.0 + sqrt(1.0 + 8.0 * (double)n)) / 4.0;
	return ceil(x) == floor(x) && ceil(y) == floor(y);
}

int main(void) {
	ll i, x = 3;
	for (i = 286; !Judge(x); i++)
		x = i * (i + 1) / 2;
	cout << x << "\n";
	return 0;
}
