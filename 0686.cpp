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
	int num, i = 0;
	ll n = 1, l = 1000000000000000ll, ans = 0;
	while (i < 678910) {
		ans++;
		n <<= 1;
		if (to_string(n).substr(0, 3) == "123")
			i++;
		if (n > l)
			n /= 10;
	}
	cout << ans << "\n";
	return 0;
}
