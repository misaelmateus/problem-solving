#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[10010][150];
int main(){
	string S;
	getline(cin, S);
	if(S.size() == 0) {
		cout << "1\n";
		return 0;
	}
	for( int i = 1; i < S.size(); i++ )
		while( (int)S[i-1] <= 126 - 31 ) {
			S[i-1]+=31;
			S[i]--;
		}
	for( int i = S.size()-1; i > 0; i-- ) {
		while( (int)S[i] > 126 )
			S[i]--, S[i-1] += 31;
		while( (int)S[i] < 32 )
			S[i]++, S[i-1] -= 31;
	}
	cout << S << endl;
	for(int i = 32; i <= 126; i++) dp[S.size() - 1][i] = 1;
	for(int i = S.size() -2 ; i >= 0; i--)
		for(int v = 32; v <= 132; v++){
			dp[i][v] = 0;
			if(v <= 126) dp[i][v] = dp[i+1][(int)S[i+1]];
			if(v - 31 >= 32) dp[i][v] = (dp[i][v] + dp[i+1][(int)S[i+1] + 1] ) % MOD;
			if(v - 62 >= 32) dp[i][v] = (dp[i][v] + dp[i+1][(int)S[i+1] + 2] ) % MOD;
			if(v - 93 >= 32) dp[i][v] = (dp[i][v] + dp[i+1][(int)S[i+1] + 3] ) % MOD;
		}
	cout << dp[0][(int)S[0]] << endl;
}