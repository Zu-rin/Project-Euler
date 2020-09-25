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
	ll num = 600851475143ll, ans = 0, i, ma;
	ma = sqrt(num);
	for (i = 3; i <= ma; i += 2) {
		if (num % i == 0) {
			chmax(ans, i);
			while (num % i == 0)
				num /= i;
		}
	}
	chmax(ans, num);
	cout << ans << "\n";
	return 0;
}