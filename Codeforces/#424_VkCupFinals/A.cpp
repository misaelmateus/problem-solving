#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, p, val;
	scanf("%d %d %d", &n, &k, &p);
	int a[n], b[k];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	sort(a, a+n);
	sort(b, b+k);
	int ans = 2*(1e9);
	for(int i = 0; i + n <= k; i++){
		int ans_i = 0;
		for(int j = i; j < i+n; j++){
			ans_i = max((int)abs(a[j-i] - b[j]) + abs(b[j] - p), ans_i);
		}
		ans = min(ans, ans_i);
	}

	printf("%d\n", ans);

	return 0;
}