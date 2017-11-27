#include<bits/stdc++.h>
#define MAXN 2010
using namespace std;
int dp[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false);
	string a, b;
	int k;
	cin >> a >> b >> k;
	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			if(!i && !j) continue;
			if(i == 0)
				dp[i][j] = k + dp[i][j-1];
			else if(j == 0)
				dp[i][j] = k + dp[i-1][j];
			else{
				dp[i][j] = min(dp[i-1][j-1] + abs((int)a[i-1] - (int)b[j-1]), k + min(dp[i-1][j], dp[i][j-1]));
			}

		}
	}
	cout << dp[a.size()][b.size()] << endl;
}