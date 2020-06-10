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

int Isprime(ll n) {
	for (ll i = 3; i <= (ll)sqrt(n); i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	ll sum = 0, prm = 0, i, j;
	for (i = 1; i < 100000; i += 2) {
		for (j = 1; j < 4; j++) {
			int a = i * i + j * (i + 1);
			if (Isprime(a))
				prm++;
		}
		sum += 4;
		if (sum > prm * 10)
			break;
	}
	cout << i << "\n";
	return 0;
}
