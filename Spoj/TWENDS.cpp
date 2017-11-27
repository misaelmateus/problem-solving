#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int v[MAXN];
int dp[MAXN][MAXN][2];
int main(){
	ios::sync_with_stdio(false);
	int n;
	int k = 1;
	while(cin >> n && n){
		//memset(dp, 0, sizeof(dp));
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}

		for(int t = 0; t < n; t++){
			for(int i = 0; i+t < n; i++){
				int j = i + t;
				if(i == j) dp[i][j][0] = v[i], dp[i][j][1] = 0;
				else{ 
					dp[i][j][0] = max(dp[i][j-1][1] + v[j], dp[i+1][j][1] + v[i]);
					if(v[i] >= v[j])
						dp[i][j][1] = dp[i+1][j][0];	
					else dp[i][j][1] = dp[i][j-1][0];	
				}
			}
		}
		cout << "In game " << k++ << ", the greedy strategy might lose by as many as ";
		cout << 2 * dp[0][n-1][0] - sum << " points." << endl;
	}
}