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

void Eratos(vector<char>& p) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int main(void) {
	int num = 100000000, i, j;
	ll ans = 3;
	vector<char> p(num + 1, 1);
	Eratos(p);
	for (i = 6; i <= num; i += 4) {
		char ok = 1;
		for (j = 1; ok && j * j < i; j++) {
			if (i % j == 0)
				ok = p[i / j + j];
		}
		if (ok)
			ans += i;
	}
	cout << ans << "\n";
	return 0;
}
