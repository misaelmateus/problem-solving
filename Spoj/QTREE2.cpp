#include<bits/stdc++.h>
#define MAXN 10010
#define ll long long
#define ii pair<int, int>
#define mp(a, b) make_pair(a, b)
using namespace std;

int anc[MAXN][18];
vector<ii> gr[MAXN];
int p[MAXN];
ll dist[MAXN];
int level[MAXN];
int pre_calc_lca(int n){
	for(int i = 1; i <= n; i++)
		anc[i][0] = p[i];
	for(int j = 1; j < 18; j++){
		for(int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j-1]][j-1];
	}
}


int lca(int a, int b){
	if(level[a] < level[b]) swap(a, b);
	for(int l = 17; l >= 0; l--)
		if(level[a] - (1 << l) >= level[b]) 
			a = anc[a][l];
	if(a == b) return a;
	for(int l = 17; l >= 0; l--)
		if(anc[a][l] != anc[b][l]) 
			a = anc[a][l], b = anc[b][l];
	return p[a];
}
int dfs(int u){

	for(auto v : gr[u]){
		if(v.first == p[u]) continue;
		dist[v.first] = dist[u] + (ll)v.second;
		level[v.first] = level[u] + 1;
		p[v.first] = u;
		dfs(v.first);
	}

}

int kth_element(int a, int k){
	k--; 
	for(int l = 17; l >= 0; l--)
		if((1 << l) <= k ){
			k -= (1 << l), a = anc[a][l];
		}
	return a;
}
int query1(int a, int b){
	int u = lca(a, b);
	return dist[a] + dist[b] - 2*dist[u];	
}
int query2(int a, int b, int k){
	int u = lca(a, b);
	int q_tot = level[a] + level[b] - 2*level[u] + 1;
	int q1 = level[a] - level[u] + 1;
	if(q1 >= k)
		return kth_element(a, k);
	return kth_element(b, q_tot - (k-1));
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		memset(level, 0, sizeof(level));
		memset(dist, 0, sizeof(dist));
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			gr[i].clear();
		int a, b, c;
		char s[6];
		for(int i = 0; i < n-1; i++){
			scanf("%d %d %d", &a, &b, &c);
			gr[a].push_back(mp(b, c));
			gr[b].push_back(mp(a, c));
		}
		dfs(1);
		pre_calc_lca(n);

		while(1){
			scanf(" %s", s);
			if(s[1] == 'O') break;
			scanf("%d %d", &a, &b);
			if(s[1] == 'I'){
				printf("%d\n", query1(a, b));
			}
			else if(s[1] == 'T') {
				scanf("%d", &c);
				printf("%d\n", query2(a, b, c));
			}
		}
		printf("\n");
	}
}