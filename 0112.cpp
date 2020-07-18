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

char Judge(int n) {
	int i = 0, d = 0, p = n % 10, a;
	n /= 10;
	while (n) {
		a = n % 10;
		if (p < a)
			i = 1;
		else if (p > a)
			d = 1;
		p = a;
		n /= 10;
	}
	return i && d;
}

int main(void) {
	int num = 1e7, i, bn = 2178 * 9;
	for (i = 21781; i < num; i++) {
		if (Judge(i))
			bn++;
		if (i * 99 == bn * 100)
			break;
	}
	cout << i << "\n";
	return 0;
}
