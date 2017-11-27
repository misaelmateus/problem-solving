#include<bits/stdc++.h>
using namespace std;
int dp[60];
int main(){
	ios::sync_with_stdio(false);	
	string s;
	cin >> s;
	//dp[i][j] = i == j -> dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1] + 1);

	for (int i = 0; i <= s.size(); i++) {
		dp[i] = 1;
	}

	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		ans = max(ans, dp[i]);
		for (int j = i + 1; j < s.size(); j++) {
			if (s[j] > s[i]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}

	printf("%d\n", 26 - ans);
	return 0;
}