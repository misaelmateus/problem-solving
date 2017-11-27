#include<bits/stdc++.h>
#define MAXN 502
using namespace std;
int ye[MAXN][MAXN], bl[MAXN][MAXN], dp[MAXN][MAXN];
int sum_ye[MAXN][MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);	
	int n, m;
	
	while(cin >> n >> m && n){
		memset(sum_ye, 0, sizeof(sum_ye));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> ye[i][j];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> bl[i][j];

		for(int l = n-1; l >= 0; l--)
			for(int i = l; i >= 0; i--)
				for(int j = 0; j < m; j++)
					sum_ye[i][l][j] = ye[i][j] + (i < l ? sum_ye[i+1][l][j] : 0) + (j > 0 ? sum_ye[i][l][j-1] : 0) - ( j > 0 && i < l ? sum_ye[i+1][l][j-1] : 0);


		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				dp[i][j] = 0;
				int sum = 0;
				for(int l = 0; l <= i+1; l++){
					dp[i][j] = max(dp[i][j], sum + (l <= i ? sum_ye[l][i][j] : 0) + (l > 0 && j > 0 ? dp[l-1][j-1] : 0));
					if(l < n)
						sum += bl[l][j];
				}
			}
		cout << dp[n-1][m-1] << endl;
	}
}