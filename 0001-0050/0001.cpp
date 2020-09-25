#include <iostream>
#include <vector>
#include <string>
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
	int num, i;
	ll sum = 0;
	for (i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	cout << sum;
	return 0;
}