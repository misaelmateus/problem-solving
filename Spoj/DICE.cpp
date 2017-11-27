#include<bits/stdc++.h>
#define MAXN 1000100
#define ld long double
using namespace std;
double dp[600][2000];
int main(){
	int t;
	dp[0][0] = 1;
	for(int i = 1; i < 600; i++)
		for(int j = 0; j < 2000; j++)
			for(int l = j-1; l >= j-6 && l >= 0; l--)
				dp[i][j] += dp[i-1][l] * 1.0 / 6;
	
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		if(n >= 600 || k >= 2000)
			cout << 0 << endl;
		else cout << (int)(dp[n][k]*100) << endl;
	}
}