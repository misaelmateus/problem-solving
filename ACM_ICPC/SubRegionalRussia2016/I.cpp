#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/// x0 * y1 - x1 * y0

using namespace std;

const int N = 300000;

int n, x[N], y[N], c[2][2][2];
long long s[N];

int main() {

	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		x[i] %= 2;
		y[i] %= 2;
	}

	long long area = 0;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		area += 1LL * x[i] * y[j] - 1LL * x[j] * y[i];
	}

	if (llabs(area) % 2 == 1) {
		puts("0");
		exit(0);
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = i + 2; j < n; j++) {
			vector <int> v;
			long long now = 0;
			for (int k = i; k <= j; k++) {
				v.push_back(k);
			}
			for (int k = 0; k < v.size(); k++) {
				int A = v[k];
				int B = v[(k + 1) % v.size()];
				now += x[A] * y[B] - x[B] * y[A];

			}
			printf("%d %d %lld\n", i, j, now);
		}
	}*/

	s[0] = 0;

	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + 1LL * x[i - 1] * y[i % n] - 1LL * x[i % n] * y[i - 1];
		//printf("%d %lld\n", i, s[i]);
	}

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		if (i - 2 >= 0) {
			int j = i - 2;
			c[llabs(s[j]) % 2][abs(x[j]) % 2][abs(y[j]) % 2]++;
		}
		for (int p = 0; p < 2; p++) {
			for (int q = 0; q < 2; q++) {
				for (int r = 0; r < 2; r++) {
					long long now = s[i] - p + x[i] * r - q * y[i];
					if (llabs(now) % 2 == 0) {
						ans += c[p][q][r];
					}
				}
			}
		}
	}

	cout << max(0LL, ans - 1) << "\n";

	/*for (int i = 0; i < n; i++) {
		for (int j = i + 2; j < n; j++) {
			long long now = s[j] - s[i] + x[j] * y[i] - x[i] * y[j];
			//printf("%d %d %lld\n", i, j, now);
		}
	}*/

	return 0;

}

