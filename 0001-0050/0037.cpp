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

void Eratos(vector<int> & p, queue<int> & que) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			que.push(i);
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int Judge(int n, vector<int> &p) {
	int a = n, b = 10;
	while (a > 0) {
		if (!p[a])
			return 0;
		a /= 10;
	}
	while (b < 1000000) {
		if (!p[n % b])
			return 0;
		b *= 10;
	}
	return 1;
}

int main(void) {
	int num = 0, i;
	ll ans = 0;
	vector<int> p(1000000, 1);
	queue<int> que;
	Eratos(p, que);
	while (que.front() < 10)
		que.pop();
	while (num < 11) {
		int a = que.front();
		que.pop();
		if (Judge(a, p)) {
			ans += a;
			num++;
		}
	}
	cout << ans << "\n";
	return 0;
}
