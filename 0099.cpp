#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>
#include <fstream>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

double Pow(double n, ll k) {
	double ans = 1, a = n;
	while (k > 0) {
		if (k & 1)
			ans *= a;
		a *= a;
		k >>= 1;
	}
	return ans;
}

double Log(ll n, ll k) {
	return (double)k * log10((double)n);
}

void Input(vector<double> & d) {
	ifstream fin("0099_input.txt");
	int i, j, k = 0;
	string s;
	d.resize(1000);
	rep(i, d.size()) {
		fin >> s;
		ll a[2] = { 0, 0 };
		k = 0;
		rep(j, s.size()) {
			if (s[j] == ',')
				k++;
			else {
				a[k] *= 10;
				a[k] += s[j] - '0';
			}
		}
		d[i] = Log(a[0], a[1]);
	}
	return;
}

int main(void) {
	int num, i, ans = 0;
	double ma = 0.0;
	vector<double> d;
	Input(d);
	rep(i, d.size()) {
		if (d[i] > ma) {
			ma = d[i];
			ans = i;
		}
	}
	cout << ans + 1 << "\n";
	return 0;
}
