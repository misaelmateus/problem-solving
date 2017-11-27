#include<bits/stdc++.h>
using namespace std;
int ans(long long num){
	if(num == 1) return 0;
	return (int)(num&1) + 1 +ans(num/2LL);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n, q;
		scanf("%d %d", &n, &q);
		int v[n+1];
		v[0] = 0;
		for(int i = 1; i <= n; i++){
			long long num;
			scanf("%lld", &num);
			v[i] = ans(num);
			//printf("%d\n", v[i]);
		}

		for(int i = 1; i <= n; i++){
			v[i] += v[i-1];
		}

		while(q--){
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", v[r] - v[l-1]);
		}
	}
}