#include <cstdio>

using namespace std;

int n;

int main() {

	scanf("%d", &n);

	long long a = 1LL;

	for (int i = 0; i < n; i++) {
		a = (2*a+1);
	}

	printf("%I64d\n", a);

	return 0;

}