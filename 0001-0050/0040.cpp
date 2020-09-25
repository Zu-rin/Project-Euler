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

int main(void) {
	int num, i, ans = 1;
	string s = "0123456789";
	for (i = 10; s.size() <= 1000000; i++)
		s += to_string(i);
	for (i = 10; i <= 1000000; i *= 10)
		ans *= s[i] - '0';
	cout << ans << "\n";
	return 0;
}
