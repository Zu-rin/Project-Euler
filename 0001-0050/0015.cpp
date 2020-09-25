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

ll Combi(ll n, ll k) {
	ll ans = 1, i;
	for (i = 1; i <= k; i++) {
		ans *= n--;
		ans /= i;
	}
	return ans;
}

int main(void) {
	int num, i;
	cout << Combi(40, 20) << "\n";
	return 0;
}
