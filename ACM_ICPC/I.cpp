#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, x, y;
vector < pair <int, int> > a;
vector < pair <int, int> > b;

long long solve(vector < pair <int, int> > &v) {
	long long ret = 0;
	if (v.size() == 0) {
		return 0;
	}
	while (v[0].second != 0) {
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i].second != 0) {
				long long now = (v[i].second + k - 1) / k;
				ret += 2LL * now * v[i].first;
				printf("deu %d %lld %lld\n", v[i].first, now, now * k);
				long long val = now * k;
				for (int j = i; j >= 0; j--) {
					long long tmp = min(1LL * v[i].second, val);
					val -= tmp;
					v[i].second -= tmp;
				}
				break;
			}
		}
	}
	return ret;
}

int main() {

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (x > 0) {
			a.push_back({x, y});
		} else {
			b.push_back({x, y});
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = solve(a) + solve(b);

	printf("%lld\n", ans);

	return 0;

}