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

int main(void) {
	int num, i = 0;
	ll ans = 0;
	double l, r, a, buf;
	l = log2(123.0);
	r = log2(124.0);
	a = log2(10.0);
	while (i < 678910) {
		l += a;
		r += a;
		if (ceil(l) == floor(r))
			i++;
		l = modf(l, &buf);
		r = modf(r, &buf);
		ans += buf;
	}
	cout << ans << "\n";
	return 0;
}
