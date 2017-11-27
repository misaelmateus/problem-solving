#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1010
#define MOD 1000000007
using namespace std;

int dp[MAXN][2*MAXN];

int main(){
	ios::sync_with_stdio(false);	
	string s;
	cin >> s;
	int n = s.size();
	int k;
	k = 0;
	if(s[0] == 'b') k = 1;
	dp[0][MAXN+k] = 1;
	fr(i, 1, n){
		fr(d, -1001, +1002){
			k = -1;
			if(s[i] == 'a') k = +1;
			dp[i][d+MAXN] = (dp[i-1][d+MAXN] + dp[i-1][d + MAXN + k]) % MOD;
		}
	}

	cout << dp[n-1][MAXN] << "\n";
}