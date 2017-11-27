#include<bits/stdc++.h>
using namespace std;
int dp[300][300];
int main(){
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++){
		string s;
		cin >> s;
		memset(dp, 0, sizeof(dp));
		for(int t = 1; t < s.size(); t++){
			for(int i = 0; i < s.size()-1; i++){
				if(s[i] != '{' || s[i+t] != '}') continue;
				if(t <= 2 || dp[i+1][i+t-1]) {
					dp[i][i+t] = 1;
					continue;
				}
				for(int l = i+2; l <= i+t-2; l++){
					if(l == ',' && dp[i+1][l-1] && dp[l+1][i+t-1])
						dp[i][i+t] = 1;
				}

			}
		}
		cout << "Word #" << k << ": ";
		if(dp[0][s.size()-1] == 1)
			cout << "Set\n";
		else cout << "No Set\n";
	}

}