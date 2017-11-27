#include<bits/stdc++.h>
#define ld long double
#define EPS (ld)0.00000000001
#define P 1000000000
using namespace std;

ld dp[2][40][40];
int s, r;
double f(int l, int i, int j){
	if(dp[l][i][j] > -EPS) return dp[l][i][j];
	dp[l][i][j] = 0.0;
	if(l == 0){
		dp[l][i][j] += f(0, i+1, j) * ((ld)s / P);
		dp[l][i][j] += f(1, i, j+1) * ( (ld)(P - s) / P);
	}
	else{
		dp[l][i][j] += f(0, i+1, j) * ((ld)r / P);
		dp[l][i][j] += f(1, i, j+1) * ( (ld)(P - r) / P);	
	}

	return dp[l][i][j];
}
int main(){
	cin >> s >> r;
	for(int i = 0; i < 40; i++)
		for(int j = 0; j < 40; j++)
			for(int l = 0; l < 2; l++) dp[l][i][j] = -1.0;

	for(int i = 21; i <= 30; i++)
		for(int j = 0; i - j >= 2; j++) 
			for(int l = 0; l < 2; l++) dp[l][i][j] = 1.0, dp[l][j][i] = 0;
	for(int l = 0; l < 2; l++)
		dp[l][30][29] = 1.0, dp[l][29][30] = 0.0;
	
	ld ans = 0.0;
	ans += (1.0 - f(0, 0, 0)) * f(1, 0, 0) * f(0, 0, 0) * 2;
	ans += f(0 ,0, 0) * f(0, 0, 0);
	cout << fixed << setprecision(15) << ans << endl;
	return 0;

}