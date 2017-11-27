#include<bits/stdc++.h>
#define MAXN 52
#define ll long long
using namespace std;

ll dp[MAXN][MAXN];
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		ll K;
		scanf("%d %lld", &N, &K);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < MAXN; i++) dp[N][i] = 1;
		dp[N][0] = 0;

		for(int i = N-1; i >= 0; i--)
			for(int j = 0; j < MAXN-1; j++){
				if(j == 0){
					dp[i][j] = dp[i+1][j+1] + (1LL << (N-1 - i));
				}
				else dp[i][j] = dp[i+1][j+1] + dp[i+1][j-1];
			}
		if(dp[0][0] <= K) {
			printf("-1\n");
			continue;
		}
		int j = 0;
		for(int i = 0; i < N; i++){
			if(dp[i+1][j+1] > K)
				printf("("), j++;
			else printf(")"), K -= dp[i+1][j+1], j--;
			if(j < 0){
				for(i++; i < N; i++){
					if(K & 1LL << (N - 1 - i)) printf(")");
					else printf("(");
				}
			}
		}
		printf("\n");
	}
}