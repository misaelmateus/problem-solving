#include<bits/stdc++.h>
#define MAXN 10100
using namespace std;
int v[MAXN];
vector<int> gr[MAXN];
int mark[MAXN];
unordered_set<int> d[MAXN];
vector<int> aux;
int ma;
int dfs(int u){
	mark[u] = 1;
	d[u].insert(v[u]);
	for(auto p: gr[u]){
		if(!mark[p]) dfs(p);
	}
	for(auto p: gr[u]){
		aux.clear();
		for(auto a : d[p])
			for(auto b : d[u])
				aux.push_back(__gcd(a, b));
		//cout << aux.size() << " ";
		for(auto a : aux)
			d[u].insert(a);
	}
	ma = max(ma, (int)d[u].size());
}
int main(){

	ios::sync_with_stdio(0);
	int I, S, a, b;
	cin >> I >> S;
	for(int i = 1; i <= I; i++)
		cin >> v[i];
	while(S--){
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	set<int> ans;
	for(int a = 0; a < 2; a++){
		memset(mark, 0, sizeof(mark));
		for(int i = 1; i <= I; i++){
			if(!mark[i]) 
				dfs(i);
		}
	}
	for(int i = 1; i <= I; i++)
		for(auto u : d[i]) ans.insert(u);
	//cout << ans.size() << "\n";
	cout << ma <<"\n";
}