#include <bits/stdc++.h>
#define ll long long
using namespace std;

int adj[22];
int n;
ll dp[21][(1 << 20)];
vector<int> val[(1<<20)];
map<int, int> mapa;

ll f(int mask, int i){
	if(dp[i][mask] != -1) return dp[i][mask];
	dp[i][mask] = 1LL;
	int mask1 = mask & adj[i];
	for(int j = 0; j < val[mask1].size(); j++)
		dp[i][mask] += f(mask ^ (1 << val[mask1][j]), val[mask1][j]);

	return dp[i][mask];
}

int main(){
	ios::sync_with_stdio(false);	
	memset(dp, -1, sizeof(dp));
	cin >> n;
	int m;
	cin >> m;
	for(int i = 0; i < (1 << 20); i++)
		for(int j = 0; j < 20; j++)
			if(i & (1 << j)) val[i].push_back(j);
		
	if(m == 0){
		cout << "0\n";
		return 0;
	}
	while(m--){
		int x, y;
		cin >> x >> y;
		adj[x] |= (1 << y);
		adj[y] |= (1 << x);
	}
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += f(((1 << n) - 1) - (1 << i), i) - 1;
	}
	cout << ans << endl;
	return 0;
}