#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

list<int> p;
void Init() {
	vector<int> d(2000, 1);
	for (int i = 2; i < d.size(); i++) {
		if (d[i]) {
			for (int j = i << 1; j < d.size(); j += i)
				d[j] = 0;
			p.push_back(i);
		}
	}
	return;
}

int Isprime(int n) {
	for (auto it = p.begin(); it != p.end(); it++) {
		if (n % *it == 0) {
			if (n == *it)
				return true;
			return false;
		}
	}
	return true;
}

int main(void) {
	Init();
	int num, i, a, b, ma = 0, ans;
	for (a = -999; a < 1000; a += 2) {
		for (auto b = p.begin(); *b < 1000; b++) {
			rep(i, 1000) {
				if (!Isprime(i * i + a * i + *b)) {
					if (i > ma) {
						ma = i;
						ans = a * *b;
					}
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}