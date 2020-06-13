#pragma GCC optimize ("O3")
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

int Judge(ll n) {
	int i;
	string s = to_string(n), a;
	rep(i, 8)
		a += s[i << 1];
	return a == "12345678";
}

int main(void) {
	ll num, i, a;
	for (i = 10000000; i < 100000000; i++) {
		a = i * 10 + 3;
		if (Judge(a * a)) {
			cout << a * a << "\n";
			break;
		}
		a = i * 10 + 7;
		if(Judge(a * a)) {
			cout << a * a << "\n";
			break;
		}
	}
	cout << a << "0\n";
	return 0;
}
