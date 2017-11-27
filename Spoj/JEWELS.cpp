#include<bits/stdc++.h>
#define MAXN 8010
using namespace std;
int dp[MAXN][MAXN];
int dp1[MAXN][MAXN];
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		string s1 = s;
		int n = s.size();
		reverse(s1.begin(), s1.end());

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(s[i] == s1[j]) dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i-1][j-1] : 0);
				else dp[i][j] = max((i > 0 ? dp[i-1][j] : 0 ), (j > 0 ? dp[i][j-1] : 0));
			}

		for(int i = 0; i < n; i++)
			for(int j = n-1; j >= 0; j--){
				if(s[i] == s[j]) dp1[i][j] = 1 + (i > 0 && j < n-1 ? dp1[i-1][j+1] : 0);
				else dp1[i][j] = max((i > 0 ? dp1[i-1][j] : 0 ), (j < n-1 ? dp1[i][j+1] : 0));
			}
		
	}
}