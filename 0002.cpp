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

typedef struct {
	int l, r;
} range;

class SegmentTree {
private:
	vector<ll> d;
	int size;

public:
	SegmentTree(int num, ll inidata) {
		size = IniSize(num);
		d.resize(size);
		fill(d.begin(), d.end(), inidata);
	}

	int IniSize(int num) {
		// �v�f�� num �����܂�Z�O�؂̃T�C�Y��Ԃ�
		int n = 1;
		while (n < num)
			n <<= 1;
		return (n << 1) - 1;
	}

	int Size() {
		return size;
	}

	void Update(int pos, int n) {
		// �ʒu pos(0-index) �̒l�� n �ōX�V����

		int i = pos + (d.size() >> 1);
		//d[i] = n;
		while (i > 0) {
			i = (i - 1) >> 1;
			//d[i] = min(d[(i << 1) + 1], d[(i << 1) + 2]);
		}
		return;
	}

	ll Query(const range tag) {
		// tag �Ŏw�肵���͈͂ɑ΂��Č������s��
		// tag = [a, b)
		return Query(0, tag, { 0, (Size() >> 1) + 1 });
	}

	ll Query(int pos, const range tag, range x) {
		// tag �Ŏw�肵���͈͂ɑ΂��Č������s��
		// tag = [a, b)

		if (tag.r <= x.l || x.r <= tag.l)
			return INF; // ***����***
		if (tag.l <= x.l && x.r <= tag.r)
			return d[pos];
		ll a, b, ans;
		a = Query((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 });
		b = Query((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r });
		//ans = min(a, b);
		return ans;
	}
};

int main(void) {
	int num, i = 0, ans = 2;
	vector<int> d = { 1, 2 };
	while (true) {
		num = d[i] + d[i + 1];
		if (num > 4000000)
			break;
		d.push_back(num);
		if(!(num & 1))
			ans += num;
		i++;
	}
	cout << ans << "\n";
	return 0;
}