#include<bits/stdc++.h>
#define MAXN 10010
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

int M[MAXN][MAXN];
ii ed[MAXN];
vector<int> gr[MAXN];
int p[MAXN];
int mark[MAXN][MAXN], cont;

int dist[MAXN];

void bfs(int i){
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(i);
	dist[i] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(auto &v : gr[u]){
			if(dist[v] == -1)
				q.push(v), dist[v] = dist[u] + 1;
		}
	}

}
int main(){

	int n, m, k;
	cin >> n >> m >> k;
	int tot = n;
	int pos;
	for(int i = 1; i <= k; i++){
		cin >> ed[i].ff >> ed[i].ss;
		if(ed[i].ff == ed[i].ss && ed[i].ff == 1)
			pos = i;
		M[ed[i].ff][ed[i].ss] = i;
	}
	for(int i = 1; i <= k; i++){
		if(!p[i]) p[i] = ++cont;
		mark[p[i]][p[i]] = 1;
		int l = ed[i].ff, r = ed[i].ss;
		if(l > 1 && M[l-1][r]) p[M[l-1][r]] = p[i];
		if(l < n && M[l+1][r]) p[M[l+1][r]] = p[i];
		if(r > 1 && M[l][r-1]) p[M[l][r-1]] = p[i];
		if(r < m && M[l][r+1]) p[M[l][r+1]] = p[i];
	}
	for(int i = 1; i <= k; i++){
		for(int l = max(ed[i].ff-1, 1); l <= min(ed[i].ff+1, n); l++)
			for(int r = 1; r <= m; r++)
				if(M[l][r] != 0 && abs(ed[i].ff - l) + abs(ed[i].ss - r) > 1 && !mark[p[i]][p[M[l][r]]])
					gr[p[i]].push_back(p[M[l][r]]), mark[p[i]][p[M[l][r]]] = 1;

		for(int r = max(ed[i].ss-1, 1); r <= min(ed[i].ss+1, m); r++)
			for(int l = 1; l <= n; l++)
				if(M[l][r] != 0 && abs(ed[i].ff - l) + abs(ed[i].ss - r) > 1 && !mark[p[i]][p[M[l][r]]])
					gr[p[i]].push_back(p[M[l][r]]), mark[p[i]][p[M[l][r]]] = 1;
	}
	int ult = 0;
	for(int j = 1; j <= m; j++)
		for(int i = 1; i <= n+1; i++){
			if(i == n+1 || M[i][j] ){
				tot++;
				p[tot] = ++cont;
				for(int l = ult+1; l < i; l++){
					M[l][j] = tot;
					if(j > 1 && M[l][j-1] && !mark[cont][p[M[l][j-1]]]) 
						gr[p[M[l][j-1]]].push_back(cont), gr[cont].push_back(p[M[l][j-1]]), 
						mark[cont][p[M[l][j-1]]] = 1;
					if(j < m && M[l][j+1]) 
						gr[p[M[l][j+1]]].push_back(cont), gr[cont].push_back(p[M[l][j+1]]),
						mark[cont][p[M[l][j+1]]] = 1;
				}
				ult = i;
			}
		}
	ult = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m+1; j++){
			if(j == m+1 || M[i][j] ){
				tot++;
				p[tot] = ++cont;
				for(int l = ult+1; l < i; l++){
					M[l][j] = tot;
					if(i > 1 && M[i-1][l] && !mark[cont][p[M[i-1][l]]]) 
						gr[p[M[i-1][l]]].push_back(cont), gr[cont].push_back(p[M[i-1][l]]), 
						mark[cont][p[M[i-1][l]]] = 1;
					if(i < n && M[i+1][l]) 
						gr[p[M[i+1][l]]].push_back(cont), gr[cont].push_back(p[M[i+1][l]]),
						mark[cont][p[M[i+1][l]]] = 1;
				}
				ult = j;
			}
		}

	for(int i = 1; i <= cont; i++){
		for(int j = 0; j < gr[i].size(); j++)
			cout << gr[i][j] << " ";
		cout << endl;
	}

	bfs(p[pos]);
	for(int i =1 ; i <= k ; i++)
		cout << dist[p[i]] << " ";
	cout << endl;
	int ans = (1 << 30);
	if(dist[p[M[n][m]]] != -1)
		ans = dist[p[M[n][m]]];
	for(int i = 1; i <= k; i++){
		
 		if(dist[p[i]] == -1) continue;

		if(ed[i].ff == n && ed[i].ss == m)
			ans = min(ans, dist[p[i]]);
		if(ed[i].ff == n || ed[i].ss == m)
			ans = min(ans, dist[p[i]]+1);
	}
	if(ans == (1 << 30)) ans = -1;
	cout << ans << endl;
}