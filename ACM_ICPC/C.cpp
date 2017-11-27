#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100100;

int n, k, r, x, a[N];
set <int> s;

int main() {

	scanf("%d %d %d", &n, &k, &r);

	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		x--;
		a[x] = 1;
	}

	int ans = 0;
	int now = 0;

	for (int i = 0; i < n; i++) {
		now += a[i];
		if (i - r >= 0) {
			now -= a[i - r];
		}
		if (a[i] == 0) {
			s.insert(i);
		}
		if (i + 1 >= r && now < 2) {
			while (now < 2) {
				int pos = *s.rbegin();
				now++;
				ans++;
				a[pos] = 1;
				s.erase(pos);
			}
		}
	}

	printf("%d\n", ans);

	return 0;

}