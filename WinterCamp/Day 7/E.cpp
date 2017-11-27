#include<bits/stdc++.h>
#define MAXN 50010
using namespace std;
int c[MAXN];
int ans[MAXN][2];
int level[MAXN];
int ini[MAXN], fim[MAXN];
vector<int> gr[MAXN];

int cont;
void dfs(int i, int p, int l){
	ini[i] = cont++;
	level[i] = l;
	ans[i][0] ^= c[i];

	for(auto &u : gr[i]){
		if(u == p) continue;
		dfs(u, i, l+1);
		ans[i][0] ^= ans[u][1];
		ans[i][1] ^= ans[u][0];
	}
	fim[i] = cont++;
}
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	dfs(1, -1, 0);

	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		int a = ans[1][1];
		if( level[u] & 1 )
			a ^= ans[u][0];
		else a ^= ans[u][1];
		if(level[v] & 1)
			a ^= ans[u][1];
		else a ^= ans[u][0];

		if(ini[v] >= ini[u] && ini[v] <= fim[u])
			cout << "INVALID\n";
		else if(a == 0)
			cout << "NO\n";
		else cout << "YES\n";
	}
}