#include<bits/stdc++.h>
#define MAXN 2001
using namespace std;
int dp[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	for(int t = 0; t < n; t++)
		for(int j = t; j < n; j++){
			int i = j - t;
			int age = n - (j - i);
			if(i == j) dp[i][j] = age * v[i];
			else dp[i][j] = max( dp[i+1][j] + v[i]*age, dp[i][j-1] + v[j] * age)	 ;
		}

	cout << dp[0][n-1] << endl;
}