#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
int m_x[] = {1, -1, 0, 0};
int m_y[] = {0, 0, 1, -1};

int m[60][60];
int mark[60][60];
map<pair<int, vector<int> >, int> mapa;
int N;


int verify(int i, int j){
	if(i < 0 || j < 0 || i >= N || j >= N) return 0;
	return 1;
}

int dfs(int i, int j, int M, vector<int> v){
	if(mapa[{M, v}]){
		return mapa[{M, v}];
	}
	if(!mark[i][j]){
		v.push_back(i + 51*j);
		sort(v.begin(), v.end());
	}
	mark[i][j] = 1;
	int ans = m[i][j];
	if(M == 1){
		mark[i][j] = 0;
		return mapa[{M, v}] = ans;
	}
	for(int l = 0; l < 4; l++){
		int i1 = i + m_x[l];
		int j1 = j + m_y[l];
		if(!verify(i1, j1))
			continue;
		ans = max(ans, (mark[i][j] == 0)*m[i][j] + dfs(i1, j1, M-(mark[i1][j1] == 0), v));
	}
	mark[i][j] = 0;
	return mapa[{M, v}] = ans;
}
int main(){
	int M;
	scanf("%d %d", &N, &M);
	for(int i  =0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	int ans = 0;
	vector<int> v;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			ans = max(ans, dfs(i, j, M, v));
	printf("%d\n", ans);
	return 0;
}