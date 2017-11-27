#include <bits/stdc++.h>
#define ii pair<int, int>
#define MAXN 101
using namespace std;

int pai[MAXN], peso[MAXN];

// funções do Union-Find otimizadas
int Find(int x){
	
	if(pai[x]==x) return x;
	return pai[x]=Find(pai[x]);
}
 
void join(int x, int y){
	
	x=Find(x);
	y=Find(y);
	
	if(x==y) return;
	
	if(peso[x]<peso[y]) pai[x]=y;
	if(peso[x]>peso[y]) pai[y]=x;
	
	if(peso[x]==peso[y]){
		
		pai[x]=y;
		peso[y]++;
	}
}

vector<ii> gr[MAXN];
int a, b;
int mark[MAXN];
void dfs(int u, int sum, int cont){
	mark[u] = 1;
	for(int i = 0; i < gr[u].size(); i++){
		if(mark[gr[u][i].first] == 0) dfs(gr[u][i].first, sum + gr[u][i].second, cont+1);
		else if(mark[gr[u][i].first] == 1){
			sum += gr[u][i].second;
			cont++;
			a = sum;
			b = cont;
			return ;
		}
	}
	mark[u] = 2;
}
int main()
{
	for(int i=1; i<=MAXN; i++) pai[i]=i;
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m; 
	vector< pair<int, pair<int, int> > > ar;
	for(int i = 0; i < m; i++)
	{
		int a1, b1, c1;
		cin >> a1 >> b1 >> c1;
		ar.push_back({c1, {a1, b1}});
	}
	sort(ar.begin(), ar.end());
	for(int i = m-1; i >= 0; i--){
		gr[ar[i].second.first].push_back({ar[i].second.second, ar[i].first});
		if(is){
			dfs(ar[i].second.first, 0, 0);
			cout << fixed << setprecision(15) << (double(a) / b) << endl;
			return 0;
		};
	}
	return 0;
}