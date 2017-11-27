#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007LL
#define MAXN 3500
using namespace std;

ll f(ll a){
	while(a < 0)
		a += MOD;
	return a;
}
void add(ll *a, ll b){
	*a += b;
	*a = f(*a);
	if(*a >= MOD)
		*a %= MOD;

}
ll dp[MAXN][MAXN];
ll su[MAXN][MAXN];
ll diag[MAXN][MAXN];
int main(){
	ll n, d, t, k;
	cin >> n >> d >> t >> k;
	dp[n][0] = 1LL;
	su[n][0] = 1LL;
	diag[n][0] = 1LL;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j <= t; j++){
			add(&dp[i][j], f( su[i+1][j] - (i+d <= n ? su[i+d][j] : 0 ) )  * (k-1));
			if(n - i < d)
				add(&dp[i][j], dp[n][j] );


			
			//for(int l = d; l + i <= n && j - l + d - 1 >= 0; l++)
			add(&dp[i][j], (ll) ((j > 0 && i+d <= n) ? diag[i+d][j-1] : 0) * (k-1));
			add(&dp[i][j], (ll) (n - i >= d && j-(n - i)+d > 0 ? dp[n][j-(n- i)+d-1] : 0)) ;
			//add(&dp[i][j], (ll)dp[i+l][j-l+d-1] * (ll)(i + l == n ? k : k-1));
		
			add(&su[i][j], su[i+1][j] + dp[i][j]) ;
			add(&diag[i][j], dp[i][j] + ((j > 0 && i+1 <= n)? dp[i+1][j - 1] : 0));

		}
	}

	cout << dp[0][t] << "\n";
}