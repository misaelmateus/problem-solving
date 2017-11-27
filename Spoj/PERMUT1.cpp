#include<bits/stdc++.h>
using namespace std;
int dp[15][200];
int main(){
	ios::sync_with_stdio(false);
	int d;
	cin >> d;
	while(d--){
		int n, k;
		cin >> n >> k;
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++){
			for(int l = 0; l <= k; l++){
				dp[i][l] = 0;
				for(int j = 0; j <= l && j < i; j++)
					dp[i][l] += dp[i-1][l - j];
			}
		}
		cout << dp[n][k] << endl;
	}
}