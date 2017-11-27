#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, ax, ay, bx, by;

int main() {

	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);

	scanf("%d %d %d %d %d %d", &n, &m, &ax, &ay, &bx, &by);

	if (abs(ax - bx) >= 2) {
		int x = min(ax, bx) + (abs(ax - bx) >> 1);
		printf("%d %d %d %d\n", x, 0, x, m);
	} else if (abs(ay - by) >= 2) {
		int y = min(ay, by) + (abs(ay - by) >> 1);
		printf("%d %d %d %d\n", 0, y, n, y);
	} else {
		int dx = abs(ax - bx);
		int dy = abs(ay - by);
		if (dy == 0) {
			printf("%d %d %d %d\n", min(ax, bx), 0, max(ax, bx), m);
		} else if (dx == 0) {
			printf("%d %d %d %d\n", 0, min(ay, by), n, max(ay, by));
		} else {
			printf("%d %d %d %d\n", min(ax, bx), 0, max(ax, bx), m);
		}
	}

	return 0;

}