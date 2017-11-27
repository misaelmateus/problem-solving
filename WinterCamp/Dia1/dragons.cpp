#include<bits/stdc++.h>
using namespace std;
vector<int> gr[500];

vector<pair<int, int> > v[500];
int mark[500];
int cont = 1;
void dfs(int u){
	mark[u] = cont;
	for(auto &v : gr[u]){
		if(!mark[v])
			dfs(v);
	}
}
int main(){
	ios::sync_with_stdio(false);	
	int n, f, d;
	cin >> n >> f >> d;
	while(f--){
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for(int i = 0; i < n; i++){
		if(!mark[i]) dfs(i), cont++;
	}
	while(d--){
		int i, s, g;
		cin >> i >> s >> g;
		v[mark[i]].push_back({g+1, s});
 	}
 	int ans = 0;
 	for(int i = 0; i < cont; i++){
 		int tot = 0;
 		sort(v[i].begin(), v[i].end());
 		int j = v[i].size()-1;
 		for(; j >= 0 && tot + v[i][j].second <= v[i][j].first; j--) tot += v[i][j].second;
 		if(j < 0) ans += tot;
 		else ans += max(tot, v[i][j].first);
 	}

	cout << ans << endl;
	return 0;
}