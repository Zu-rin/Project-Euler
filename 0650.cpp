#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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

void Eratos(vector<int> & d) {
	int i, j;
	vector<char> p(20000, 1);
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			d.push_back(i);
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int main(void) {
	int num = 20000, i, j;
	vector<int> p;
	Eratos(p);
	vector<list<pp>> div(num + 1);
	for (i = 1; i < div.size(); i++) {
		int buf = i;
		rep(j, p.size()) {
			int n = 0;
			while (buf % p[j] == 0) {
				buf /= p[j];
				n++;
			}
			if (n) {
				div[i].push_back(pp(j, n));
				if (buf == 1)
					break;
			}
		}
	}

	return 0;
}