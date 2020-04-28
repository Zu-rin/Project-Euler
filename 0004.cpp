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

int Judge(int n) {
	string a = "", b;
	while (n > 0) {
		a += '0' + (n % 10);
		n /= 10;
	}
	b = a;
	reverse(a.begin(), a.end());
	return a == b;
}

int main(void) {
	int num, i, j, ans = 0;
	for (i = 301; i < 1000; i++) {
		for (j = 301; j < 1000; j++) {
			if (Judge(i * j))
				chmax(ans, i * j);
		}
	}
	cout << ans << "\n";
	return 0;
}