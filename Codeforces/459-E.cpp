//   Author : Misael Mateus 
//   Submission date: 2017-03-24 17:25:04
#include<bits/stdc++.h>
#define MAXN 300100
#define ii pair<int, int>
using namespace std;

vector<ii> gr[MAXN];
vector<int> dp[MAXN];
int f(int i, int j){
	if(j == gr[i].size())
		return 0;
	if(dp[i][j] != 0)
		return dp[i][j];
	
	 
	dp[i][j] = f(i, j+1);
	int next = gr[i][j].second;
	int t = gr[i][j].first;
	int p = (int)(upper_bound(gr[next].begin(), gr[next].end(), (ii){t, MAXN}) - gr[next].begin());
	dp[i][j] = max(dp[i][j], 1 + f(next, p));
	return dp[i][j];
}
int main(){
	ios::sync_with_stdio( false );
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){	
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		gr[ui].push_back({wi, vi});
	}

	for(int i = 1; i <= n; i++){
		sort(gr[i].begin(), gr[i].end());
		dp[i] = vector<int>(gr[i].size(), 0);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(gr[i].size())
			ans = max(ans, f(i, 0));
	}

	cout << ans << "\n";

	return 0;
}