#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <boost/multiprecision/cpp_dec_float.hpp>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>> Real;

Real Pow(Real n, ll k) {
	Real ans = 1, a = n;
	while (k > 0) {
		if (k & 1)
			ans *= a;
		a *= a;
		k >>= 1;
	}
	return ans;
}

int main(void) {
	int num, i;
	Real lim = Pow(10, 999);
	vector<Real> d(10000);
	d[1] = d[2] = 1.0;
	for (i = 3; i < d.size(); i++) {
		d[i] = d[i - 1] + d[i - 2];
		if (d[i] >= lim) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
