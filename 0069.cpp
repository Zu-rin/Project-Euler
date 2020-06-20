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
	ll num = 1000000, i, j, prd = 1, ans;
	double tot = 0.0, a;
	vector<int> p(num + 1, 1);
	for (i = 2; prd * i <= num; i++) {
		if (p[i]) {
			prd *= i;
			for (j = i << 1; j <= num; j += i)
				p[j] = 0;
			int sum = 1;
			for(j = i + 1; j < prd; j++) {
				if (p[j])
					sum++;
			}
			a = (double)prd / (double)sum;
			if (tot < a) {
				tot = a;
				ans = prd;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
