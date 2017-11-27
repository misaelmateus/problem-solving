//   Author : Misael Mateus 
//   Submission date: 2017-11-01 23:48:36
#include <cstdio>
#include <algorithm>

using namespace std;

const long long INF = (long long) 1e18;

long long n, m, k, a[30], t[30], p[30];

int main() {

  while (scanf("%lld %lld %lld", &n, &m, &k) != EOF) {
    for (int i = 0; i < 2; i++) {
      scanf("%lld %lld %lld", &a[i], &t[i], &p[i]);
    }
    long long res = INF;
    for (long long x = 0; x <= n; x++) {
      long long px1 = (x + a[0] - 1) / a[0];
      long long cx1 = px1 * p[0];
      long long rn = n - x;
      if (k <= t[1]) {
        long long tt = x * t[0] + rn * k;
        if (tt <= m) {
          res = min(res, cx1);
        }
      } else {
        long long low = 0;
        long long high = rn;
        while (low <= high) {
          long long mid = (low + high) / 2;
          long long rn2 = rn - mid;
          long long now = x * t[0] + mid * t[1] + k * rn2;
          if (now <= m) {
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        }
        if (low > rn) {
          continue;
        }
        long long px2 = (low + a[1] - 1) / a[1];
        long long cx2 = px2 * p[1];
        res = min(res, cx1 + cx2);
      }
    }
    printf("%lld\n", res == INF ? -1 : res);
  }

  return 0;

}
