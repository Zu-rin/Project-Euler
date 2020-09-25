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

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}



int Judge(int a, int b) {
	int x, g, A, B, s, t;
	g = gcd(a, b);
	A = a / g;
	B = b / g;
	for (x = 1; x < 10; x++) {
		g = gcd(s = 10 * a + x, t = 10 * b + x);
		if (s / g == A && t / g == B)
			return true;
		g = gcd(s = 10 * a + x, t = b + 10 * x);
		if (s / g == A && t / g == B)
			return true;
		g = gcd(s = a + 10 * x, t = 10 * b + x);
		if (s / g == A && t / g == B)
			return true;
		g = gcd(s = a + 10 * x, t = b + 10 * x);
		if (s / g == A && t / g == B)
			return true;
	}
	return false;
}

int main(void) {
	int num, i, a, b, n = 1, d = 1;
	for (b = 2; b < 10; b++) {
		for (a = 1; a < b; a++) {
			if (Judge(a, b)) {
				n *= a;
				d *= b;
			}
		}
	}
	cout << d / gcd(n, d) << "\n";
	return 0;
}
