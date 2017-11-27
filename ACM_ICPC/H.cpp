#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define ff first
#define ss second
using namespace std;
#define MAXN 200010

ll dp[MAXN];
ii v[MAXN];
int main(){
	ll n, k;
	int j;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
		cin >> v[i].first >> v[i].second;
	v[k] = {n+1, n+1};
	k++;

	sort(v, v+k);

	dp[k-1] = 0;
	for(int i = k-2; i >= 0; i--){
		dp[i] = dp[i+1] + v[i+1].first - v[i].first;
		j = (int)(lower_bound(v, v+k, (ii){v[i].second + 1, -1}) - v);
		dp[i] = min(dp[i], dp[j] + v[j].first - v[i].second - 1);
	}

	cout << dp[0] + v[0].first - 1 << "\n";

	return 0;
}