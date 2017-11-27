//   Author : Misael Mateus 
//   Submission date: 2017-11-01 21:04:02
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, a[N], d[N], r[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int low = 0;
    int high = (int) 1e9;

    while (low <= high) {
        int mid = (low + high) / 2;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= mid) {
                j++;
            }
            //printf("dbg %d %d\n", i, j);
            r[i] = j;
        }
        for (int i = 0; i <= n; i++) {
            d[i] = 0;
        }
        d[0] = 1;
        d[1] = -1;
        for (int i = 0; i <= n; i++) {
            if (i != 0) {
                d[i] += d[i - 1];
            }
            //printf("dbg2 %d %d\n", i, d[i]);
            if (i == n || d[i] == 0) {
                continue;
            }
            if (r[i] - i >= m) {
                d[min(n, i + m)]++;
                d[r[i] + 1]--;
            }
        }
        //printf("dbg3 %d %d\n", mid, d[n]);
        if (d[n] == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", low);

    return 0;

}
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, a[N], d[N], r[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int low = 0;
    int high = (int) 1e9;

    while (low <= high) {
        int mid = (low + high) / 2;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= mid) {
                j++;
            }
            //printf("dbg %d %d\n", i, j);
            r[i] = j;
        }
        for (int i = 0; i <= n; i++) {
            d[i] = 0;
        }
        d[0] = 1;
        d[1] = -1;
        for (int i = 0; i <= n; i++) {
            if (i != 0) {
                d[i] += d[i - 1];
            }
            //printf("dbg2 %d %d\n", i, d[i]);
            if (i == n || d[i] == 0) {
                continue;
            }
            if (r[i] - i >= m) {
                d[min(n, i + m)]++;
                d[r[i] + 1]--;
            }
        }
        //printf("dbg3 %d %d\n", mid, d[n]);
        if (d[n] == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", low);

    return 0;

}
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, a[N], d[N], r[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int low = 0;
    int high = (int) 1e9;

    while (low <= high) {
        int mid = (low + high) / 2;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= mid) {
                j++;
            }
            //printf("dbg %d %d\n", i, j);
            r[i] = j;
        }
        for (int i = 0; i <= n; i++) {
            d[i] = 0;
        }
        d[0] = 1;
        d[1] = -1;
        for (int i = 0; i <= n; i++) {
            if (i != 0) {
                d[i] += d[i - 1];
            }
            //printf("dbg2 %d %d\n", i, d[i]);
            if (i == n || d[i] == 0) {
                continue;
            }
            if (r[i] - i >= m) {
                d[min(n, i + m)]++;
                d[r[i] + 1]--;
            }
        }
        //printf("dbg3 %d %d\n", mid, d[n]);
        if (d[n] == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", low);

    return 0;

}
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, a[N], d[N], r[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int low = 0;
    int high = (int) 1e9;

    while (low <= high) {
        int mid = (low + high) / 2;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= mid) {
                j++;
            }
            //printf("dbg %d %d\n", i, j);
            r[i] = j;
        }
        for (int i = 0; i <= n; i++) {
            d[i] = 0;
        }
        d[0] = 1;
        d[1] = -1;
        for (int i = 0; i <= n; i++) {
            if (i != 0) {
                d[i] += d[i - 1];
            }
            //printf("dbg2 %d %d\n", i, d[i]);
            if (i == n || d[i] == 0) {
                continue;
            }
            if (r[i] - i >= m) {
                d[min(n, i + m)]++;
                d[r[i] + 1]--;
            }
        }
        //printf("dbg3 %d %d\n", mid, d[n]);
        if (d[n] == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", low);

    return 0;

}
