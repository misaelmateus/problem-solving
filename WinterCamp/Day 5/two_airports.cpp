#include<bits/stdc++.h>
#define MAXN 1050
using namespace std;

int dp[MAXN][MAXN][3];
int main(){
	int n;
	cin >> n;
	vector<int> v[2];
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[b-1].push_back(a);
	}
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			for(int l = 0; l < 3; l++) dp[i][j][l] = (100000000);
	dp[0][0][1] = 0;
	for(int i = 0; i < v[0].size(); i++)
		for(int j = 0; j < v[1].size(); j++)
			for(int l = 0; l < 3; l++){
				if(dp[i][j][l] >= 100000000) continue;
				for(int k1 = 1; k1 <= 11 && k1 + i <= v[0].size(); k1++){
					for(int k2 = 1; k1 + k2 <= 12 && k2 + j <= v[1].size(); k2++){
						if(l + 1 < 3)
						dp[i+k1][j+k2][l+1] = min(dp[i+k1][j+k2][l+1], dp[i][j][l]+1);
						if(l - 1 > 0)
						dp[i+k1][j+k2][l-1] = min(dp[i+k1][j+k2][l-1], dp[i][j][l]+1);
					}
				}
			}
	int ans = 100000000;
	for(int l = 0; l < 3; l++) ans =min(ans, dp[v[0].size()][v[1].size()][l]);
	if(ans == 100000000) ans = -1;
	cout << ans << "\n";
}