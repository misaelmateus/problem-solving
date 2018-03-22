#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

int N, K;
int dp[111][111][111];
int f(int n, int k, int y){
	if(n < 0 || (n == N && y != 0) || (n != 0 && k == 0) || (n == 0 && k != 0) || (k == 1 && n != 1))
		return INF;
	if(k == 1){
		return y;
	}
	if(dp[n][k][y] != -1)
		return dp[n][k][y];
	int ans = INF;
	for(int x = 1; x <= n; x++){
		ans = min(ans, f(n-x, k-1, x) + y*x);
	}
	return dp[n][k][y] = ans;
}
int main(){
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	int ans = f(N-1, K-1, 1);
	if(ans >= INF)
			cout << -1 << endl;
	else cout << ans << endl;
}