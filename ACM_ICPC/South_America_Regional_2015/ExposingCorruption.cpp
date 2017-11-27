#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define ff first
#define ss second
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define MAXD 10010
using namespace std;


vector<int> gr[2*MAXN];
int d[MAXN], p[MAXN];
int mark[MAXN*2];
void dfs(int u, ii& a, int &price, int flag){
	mark[u] = 1;
	if(!flag)
		a.ff++, price += d[u];
	else a.ss++, price += p[u-MAXN];
	for(auto v : gr[u]){
		if(!mark[v])
			dfs(v, a, price, flag^1);
	}
}

vector<ii> knap_d, knap_p;
int dp[MAXN][MAXD];
int knapsack(vector<ii> &v, int B){
	if(v.size() == 0) return 0;
	memset(dp, 0, sizeof(dp));
	rep(j, MAXD){
		rep(i, (int)v.size() )
			if(i == 0) dp[i][j] = (j - v[i].ss >= 0)*v[i].ff;
			else if(j - v[i].ss < 0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].ss] + v[i].ff);
		}
	return dp[v.size()-1][B];
}
int main(){
	ios::sync_with_stdio(false);	
	int D, P, R, B;
	int a, b;
	while(cin >> D >> P >> R >> B){
		memset(mark, 0, sizeof(mark));
		rep(i ,2*MAXN) gr[i].clear();
		knap_d.clear();
		knap_p.clear();

		
		rep(i, D) cin >> d[i];
		rep(i, P) cin >> p[i];
		rep(i, R){
			cin >> a >> b;
			a--, b--;
			gr[a].push_back(b+MAXN);
			gr[b+MAXN].push_back(a);
		}
		rep(i, D){
			if(mark[i]) continue;
			ii a(0, 0);
			int price = 0;
			dfs(i, a, price, 0);
			if(a.first < a.second)
				knap_d.push_back({a.ss - a.ff, price});
			else knap_p.push_back({a.ff - a.ss, price});
		}
		rep(i, P){
			if(mark[i+MAXN]) continue;
			ii a(0, 0);
			int price = 0;
			dfs(i+MAXN, a, price, 1);
			if(a.first < a.second)
				knap_d.push_back({a.ss - a.ff, price});
			else knap_p.push_back({a.ff - a.ss, price});
		}
		int ans1 = D + knapsack(knap_d, B), ans2 = P + knapsack(knap_p, B);
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}