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

int Isprime(int n) {
	if (!(n & 1))
		return 0;
	for (int i = 3; i <= (int)sqrt(n); i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int num = 500000, i, con = 0, ans;
	list<int> p{ 2 };
	for (i = 3; i < num; i++) {
		if (Isprime(i)) {
			con = 0;
			p.push_back(i);
		}
		else {
			con++;
			int n = i, pn = 0;
			for (auto it = p.begin(); it != p.end() && n > 1; it++) {
				if (n % *it == 0) {
					pn++;
					while (n % *it == 0)
						n /= *it;
				}
			}
			if (pn != 4)
				con = 0;

		}
		if (con == 4) {
			ans = i - 3;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
