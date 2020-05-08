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
	ll p = 0, i = 2, k = 3, ans = 1;
	while (k <= 1001 * 1001) {
		p++;
		ans += k;
		if (p % 4 == 0)
			i += 2;
		k += i;
	}
	cout << ans << "\n";
	return 0;
}
