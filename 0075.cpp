#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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

int Sum(const vector<int> & d) {
	int ans = 0;
	for (auto i : d) {
		ans += i;
	}
	return ans;
}

int main(void) {
	int num = 30000, i, j, ans = 0;
	vector<set<pp>> d(150001);
	for (i = 1; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			vector<int> a;
			a.push_back(j * j - i * i);
			a.push_back(2 * i * j);
			a.push_back(j * j + i * i);
			int sum = Sum(a), k = 1;
			if (sum >= d.size())
				break;
			sort(a.begin(), a.end());
			while (sum * k < d.size()) {
				d[sum * k].insert(pp(a[0] * k, a[1] * k));
				k++;
			}
		}
	}
	rep(i, d.size()) {
		if (d[i].size() == 1)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}