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

vector<int> k(10);
void Init() {
	k[0] = k[1] = 1;
	for (int i = 2; i < 10; i++)
		k[i] = k[i - 1] * i;
	return;
}

int Judge(int n) {
	int num = n, ans = 0;
	while (n > 0) {
		ans += k[n % 10];
		n /= 10;
	}
	return num == ans;
}

int main(void) {
	int num, i;
	ll ans = 0;
	Init();
	for (i = 10; i < 9999999; i++) {
		if (Judge(i))
			ans += i;
	}
	cout << ans << "\n";
	return 0;
}