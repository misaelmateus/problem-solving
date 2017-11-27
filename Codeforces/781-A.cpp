//   Author : Misael Mateus 
//   Submission date: 2017-07-08 20:43:58
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 200010
using namespace std;

int max_color;
int c[MAXN];
vector<int> gr[MAXN];
void dfs(int u, int p){
	int color = 1;
	for(auto &v : gr[u]){
		if(v == p) continue;
		while(color == c[u] || color == c[p]) color++;
		c[v] = color++;
		max_color = max(max_color, c[v]);
		dfs(v, u);
	}
}


int main(){
	ios::sync_with_stdio(false);	
	int n, u, v;
	cin >> n;

	rep(i, n-1){
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	max_color = c[1] = 1; 
	dfs(1, -1);

	cout << max_color << "\n";
	fr(i, 1, n+1){
		cout << c[i] << " ";
	}
	cout << "\n";
	return 0;
}