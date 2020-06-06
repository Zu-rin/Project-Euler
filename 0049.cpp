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

void Eratos(vector<int> & p) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int Judge(int a, int b, int c) {
	string x = to_string(a), y = to_string(b), z = to_string(c);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	return x == y && y == z;
}

int main(void) {
	int num, i, j;
	vector<int> p(10000, 1);
	Eratos(p);
	for (i = 1001; i < p.size(); i++) {
		if (p[i]) {
			for (j = 1; p.size(); j++) {
				int a = i + j, b = i + (j << 1);
				if (b >= p.size())
					break;
				if (p[a] && p[b] && Judge(i, a, b))
					cout << i << a << b << "\n";
			}
		}
	}
	return 0;
}
