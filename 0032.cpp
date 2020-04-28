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

int Dig(int n) {
	int ans = 0;
	while (n > 0) {
		if (n % 10 == 0 || ans & 1 << (n % 10 - 1))
			return 0;
		ans |= 1 << (n % 10 - 1);
		n /= 10;
	}
	return ans;
}

int Judge(int n) {
	int d = Dig(n), a, b, k = (1 << 9) - 1;
	if (!d)
		return false;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			a = Dig(i);
			if (!a || d & a)
				continue;
			a |= d;
			b = Dig(n / i);
			if (b && (a ^ b) == k)
				return true;
		}
	}
	return false;
}

int main(void) {
	int num, i;
	ll ans = 0;
	for (i = 1234; i <= 98765; i++) {
		if (Judge(i))
			ans += i;
	}
	cout << ans << "\n";
	return 0;
}