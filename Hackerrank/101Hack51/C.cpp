#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
vector<int> gr[MAXN];
int V[MAXN];
int v[3];
long long ans = 0;

int dist[MAXN][8];
int dfs(int u, int p){
	int cont = V[u];
	for(auto &l : gr[u]){
		if(l != p) cont += dfs(l, u);
	}

	if(u != 1)
		ans += (long long)cont * v[cont-1];
	return cont;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, v1, v2, v3;
		cin >> n >> v[0] >> v[1] >> v[2] >> v1 >> v2 >> v3;
		v[1] = min(v[1], v[0]);
		v[2] = min(v[2], v[1]);
		memset(V, 0, sizeof(V));
		V[v1]++, V[v2]++, V[v3]++;


		for(int i = 0; i < n; i++)
			gr[i].clear();
		for(int i = 0; i < n-1; i++){
			int a, b;
			cin >> a >> b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}

		ans = 0LL;
		dfs(1, 0);
		cout << ans << endl;
	}
}