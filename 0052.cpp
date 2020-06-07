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

int Judge(int a, int b) {
	string s = to_string(a), t = to_string(b);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

int main(void) {
	int num, i, j, k = 10, ok;
	for (k = 10; k <= 100000000; k *= 10) {
		for (i = k; 6 * i < k * 10; i++) {
			ok = true;
			for (j = 2; j <= 6; j++) {
				if (!Judge(i, i * j)) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				rep(j, 7)
					cout << i * j << "\n";
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
