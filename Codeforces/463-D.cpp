//   Author : Misael Mateus 
//   Submission date: 2016-05-19 21:32:46
#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
vector<int> pai[MAXN];
int dp[MAXN];
int dfs(int i){
	if(pai[i].size() == 0)
		return 1;
	if(dp[i] != 0)
		return dp[i];
	int maior = -1;
	for(int j = 0; j < pai[i].size(); j++)
		maior = max(maior, dfs(pai[i][j]));
	return dp[i] = maior + 1;
}
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int v[K][N];
	
	for(int i = 0; i < K; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &v[i][j]);
	int matriz[N+1][N+1][K];
	memset(matriz, 0, sizeof(matriz));
	for(int l = 0; l < K; l++)
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++){
			matriz[v[l][i]][v[l][j]][l] = 1;
		}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
		{
			int teste = true;
			for(int l = 0; l < K; l++)
				if(!matriz[i][j][l])
					teste = false;
			if(teste)
				pai[i].push_back(j);
		}
		
	int maior = -1;
	for(int i = 1; i <= N; i++)
		if(dfs(i) > maior)
			maior = dfs(i);
	
	printf("%d\n", maior);
}
