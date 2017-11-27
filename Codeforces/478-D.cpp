//   Author : Misael Mateus 
//   Submission date: 2017-03-08 21:09:30
#include<bits/stdc++.h>
#define MAXN 200100
#define L 1000000007
using namespace std;
int main(){
	ios::sync_with_stdio( false );
	int r, g;
	cin >> r >> g;
	int h;
	for(h = 1; h*(h+1)/2 <= r+g; h++); h--;

	vector<int> dp(MAXN, 0), aux(MAXN);
	dp[0] = 1;
	for(int i = 1; i <= h; i++){
		aux = vector<int>(MAXN, 0);
		aux[0] = 1;
		for(int j = MAXN-1; j > 0; j--){
			aux[j] = (dp[j] + (j - i >= 0 ? dp[j-i] : 0) )%L;
		}
		dp = aux;
	}

	int ans = 0;
	for(int i = max(0, (h)*(h+1)/2 - g); i <= r; i++)
		ans = (ans + dp[i])%L;
	cout << ans << endl;
	return 0;
}