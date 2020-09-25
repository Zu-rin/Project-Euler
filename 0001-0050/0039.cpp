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
	int num, p, i, j, k, ans;
	for (p = 10; p <= 1000; p++) {
		int a = 0;
		for (i = 1; i < (p >> 1); i++) {
			for (j = i; j < (p >> 1); j++) {
				k = p - i - j;
				if (k < j)
					break;
				if (i * i + j * j == k * k)
					a++;
			}
		}
		// あらかじめ maximum number of solutions = 8 を計算しておく
		if (a == 8)
			ans = p;
	}
	cout << ans << "\n";
	return 0;
}
