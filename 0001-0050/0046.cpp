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
	int num = 2000000, i;
	list<int> p;
	vector<int> sq(num, 0);
	rep(i, 1000)
		sq[2 * i * i] = 1;
	for (i = 3; i < num; i += 2) {
		if (Isprime(i))
			p.push_back(i);
		else {
			int ok = 0;
			for (auto it = p.begin(); it != p.end(); it++) {
				int x = i - *it;
				if (sq[x])
					ok = 1;
			}
			if (!ok)
				break;
		}
	}
	cout << i << "\n";
	return 0;
}
