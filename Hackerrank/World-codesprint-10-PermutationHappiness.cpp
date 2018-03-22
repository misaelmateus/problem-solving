#include<bits/stdc++.h>
#define MAXN 3010
#define P 1000000007LL
using namespace std;
long long dp[MAXN][2*MAXN];
long long G(long long n, long long k){
	if(dp[n][k] != -1) return dp[n][k];
	if(n == 1){
		if(k == 0)
			return 1;
		else return 0;
	}

	return dp[n][k] = ((k*G(n-1, k))%P + 2*G(n-1, k-1) + ((n - k)*G(n-1, k-2))%P)%P;
}
int main(){
	memset(dp, -1, sizeof(dp));
	long long T;
	cin >> T;
	while(T--){
		long long n, k;
		cin >> n >> k;
		k = n-k;
		long long ans = 0LL;
		for(long long k1 = k; k1 > 0; k1--){
			ans = (ans + ((G(n, (k1-1)*2) + G(n, k1*2))*(P/2LL + 1))%P + G(n, (k1-1)*2 + 1)  )%P;
		}
		cout << ans << "\n";
	}
}