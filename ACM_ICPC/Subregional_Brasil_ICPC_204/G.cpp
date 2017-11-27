#include<bits/stdc++.h>
#define MAXN 110
using namespace std;
char s[MAXN][MAXN];
int dist[MAXN][MAXN];
int m_x[] = {1, -1, 0, 0};
int m_y[] = {0, 0, 1, -1};
int N;

int verify(int mask, int i, int j){
	if(s[i][j] >= 'a' && s[i][j] <= 'z'){
		int a = (int)(s[i][j] - 'a');
		if(mask & (1 << a)) return 0;
		return 1;
	}
	else{
		int a = (int)(s[i][j] - 'A');
		if(mask & (1 << a)) return 1;
		return 0;
	}
}
int dfs(int mask){
	if(!verify(mask, 0, 0)) return (1 << 30);
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++) dist[i][j] = (1 << 30); 
	queue<pair<int, int> > q;
	dist[0][0] = 1;
	q.push({0, 0});
	while(!q.empty()){
		int i = q.front().first, j = q.front().second;
		q.pop();
		for(int l = 0; l < 4; l++){
			int i1 = i + m_x[l], j1 = j + m_y[l];
			if(i1 < 0 || j1 < 0 || i1 >= N || j1 >= N || dist[i1][j1] != (1 << 30) || !verify(mask, i1, j1)) continue;
			dist[i1][j1] = dist[i][j] + 1;
			q.push({i1, j1});
		}
	}
	return dist[N-1][N-1];
}
int main(){
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf(" %s", s[i]);
	int ans = (1 << 30);
	for(int mask = 0; mask < (1 << 10); mask++){
		ans = min(ans, dfs(mask));
	}
	if(ans == (1 << 30)) ans = -1;
	printf("%d\n", ans);
	return 0;
}