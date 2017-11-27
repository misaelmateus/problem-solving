#include<bits/stdc++.h>
#define MAXN 1010
#define ll long long
using namespace std;
ll dp[MAXN][MAXN];
ll c[MAXN][MAXN];
int L[MAXN][MAXN];
ll sum[MAXN][MAXN];
pair<ll, ll> v[MAXN];

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	while(cin >> n >> k){
		for(int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
		}
		//sort(v, v+n);
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if(i == j) sum[i][j] = v[i].second;
				else sum[i][j] = v[j].second + sum[i][j-1];

				if(i == j) c[i][j] = 0;
				else c[i][j] = sum[i][j-1]*(v[j].first - v[j-1].first) + c[i][j-1];

			}
		}
		for(int i = 0; i <= n; i++)
			dp[i][0] = (1LL << 60), L[i][0] = 0;
		for(int j = 1; j <= k; j++){
			L[n][j] = n-1;
			for(int i = n-1; i >= 0; i--){
				dp[i][j] = (1LL << 60);
				for(int l = L[i][j-1]; l <= L[i+1][j] && l <= i; l++){
					if(dp[i][j] > (l > 0 ? dp[l-1][j-1] : 0) + c[l][i])
						dp[i][j] = (l > 0 ? dp[l-1][j-1] : 0) + c[l][i], L[i][j] = l;
				}
			}
		}
		cout << dp[n-1][k] << endl;
	}
	return 0;
}