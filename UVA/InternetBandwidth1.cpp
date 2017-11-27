#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int gr[MAXN][MAXN];
int s, t, n;
int p[MAXN];

int augment(int u, int flow = 1e9){
	if(p[u] == 0){
		return flow;
	}
	int fl = augment(p[u], min(flow, gr[p[u]][u]));
	gr[p[u]][u] -= fl;
	gr[u][p[u]] += fl;
	return fl;
}
int bfs(){
	memset(p, -1, sizeof(p));
	p[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i < MAXN; i++){
			if(p[i] == -1 && gr[u][i] > 0){
				p[i] = u;
				q.push(i);
			}
		}
	}
	return p[t] != -1;
}

int main(){
	int k = 1;
	while(scanf("%d", &n) && n){
		memset(gr, 0, sizeof(gr));
		int m;
		scanf("%d %d %d", &s, &t, &m);
		while(m--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			gr[a][b] += c;
			gr[b][a] += c;
		}
		int ans = 0;
		while(bfs()){
			ans += augment(t);
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", k++, ans);
	}
}