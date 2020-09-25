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

vector<ll> d;
void Search(int v, ll n) {
	if (v == 0) {
		d.push_back(n);
		return;
	}
	int i;
	rep(i, 10) {
		if (v & (1 << i)) {
			Search(v ^ (1 << i), n * 10l + i);
		}
	}
	return;
}

int main(void) {
	int num, i;
	Search((1 << 10) - 1, 0);
	cout << d[999999] << "\n";
	return 0;
}
