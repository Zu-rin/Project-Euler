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

int Divnum(ll n) {
	ll i, lim = sqrt(n), ans = 2;
	for (i = 2; i < lim; i++) {
		if (n % i == 0)
			ans += 2;
	}
	if (lim * lim == n)
		ans++;
	return ans;
}

int main(void) {
	int num = 1, i;
	for (i = 2; Divnum(num) <= 500; i++) {
		num += i;
	}
	cout << num << "\n";
	return 0;
}