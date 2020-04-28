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
	ll a = 0, b = 0, i, n = 100;
	a = n * (n + 1) * (2 * n + 1) / 6ll;
	b = (n + 1) * n / 2ll;
	b *= b;
	cout << abs(a - b) << "\n";
	return 0;
}