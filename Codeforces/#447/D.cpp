#include<bits/stdc++.h>
#define MAXN 1000100
#define MAXL 21
#define ll long long
using namespace std;
ll s[MAXN][2*MAXL];
int q[MAXN][2*MAXL]; 
int 
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int h = 1; h < 2*MAXL; h++)
		for(int i = n/2; i > 0; i--){
			s[i][h] = s[2*i][h-1] + q[2*i][h-1] + 1LL;
			q[i][h] = q[2*i][h-1] + 1;
			if((2*i + 1) <= n){
				s[i][h] += s[2*i + 1][h-1] + q[2*i + 1][h-1] + 1LL;
				q[i][h] += q[2*i + 1][h-1] + 1;
			}
		}
	while(m--){
		int ai, hi;
		scanf("%d %d", &ai, &hi);
		int l = 0;
		ll d = 0LL;
		ll ans = 0LL;
		while(ai && hi){
			ans += s[ai][hi] - s[l][hi-1] + d*(q[ai][hi] - q[l][hi-1]);
			l = ai;
			ai /= 2;
		}
		printf("%lld\n", ans);
	}

	return 0;
}