#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[111][4001][111];
int main(){
	int n, k;
	cin >> n >> k;
	ll num;
	int q5[n], q2[n];
	vector<int> mark(n, 0);
 
	for(int i = 0; i < n; i++){
		cin >> num;
		q5[i] = q2[i] = 0;
		while(num && num % 5 == 0)
			q5[i]++, num /= 5;
		while(num && num % 2 == 0)
			q2[i]++, num /= 2;
		cout << q2[i] << " " << q5[i] << endl;
	}
	for(int i = 0; i < 111; i++)
		for(int j = 0; j < 4001; j++)
			for(int l = 0; l < 111; l++) dp[i][j][l] = -(1e9);
	int ans = 0;
	for(int i = 1; i < n; i++){
		dp[i][q2[i] - q5[i] + 2000][k] = min(q2[i], q5[i]);
		for(int j = 0; j < 4000; j++){
			for(int l = 0; l < k; l++){
				dp[i][j][l] = dp[i-1][j][l];
				if(j + q5[i] - q2[i] < 0 || j + q5[i] - q2[i] > 4000)
					continue;
				if(j - 2000 < 0)
					dp[i][j][l] = max(dp[i-1][j][l], dp[i-1][q2[i] - (q5[i] + abs(j - 2000))][k+1] + min(q5[i] + abs(j - 2000), q2[i]));
				else
					dp[i][j][l] = max(dp[i-1][j][l], dp[i-1][q2[i] + abs(j - 2000) - (q5[i])][k+1] + min(q5[i], q2[i] + abs(j - 2000)));
				
			}
			ans = max(ans, dp[i][j][0]);
		}
	}
	cout << ans << "\n";

	return 0;
}