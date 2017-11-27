#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, s, e;
		scanf("%d %d %d", &n, &s, &e);
		s--, e--;
		int count[n][10];
		int common[n][n];
		int dist[n];
		
		memset(count, 0, sizeof(count));
		memset(dist, -1, sizeof(dist));
		memset(common, 0, sizeof(common));

		for(int i = 0; i < n; i++){
			char num[22];
			scanf(" %s", num);
			for(int j = 0; j < 20; j++)
				count[i][num[j] - '0']++;
		}

		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++){
				for(int l = 0; l < 10; l++)
					common[i][j] += min(count[i][l], count[j][l]);
				common[j][i] = common[i][j];
			}
		queue<int> q;
		q.push(s);
		dist[s] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0; i < n; i++){
				if(common[i][u] == 17 && dist[i] == -1)
					dist[i] = 1 + dist[u], q.push(i);
			}
		}

		printf("%d\n", dist[e]);
	}
}