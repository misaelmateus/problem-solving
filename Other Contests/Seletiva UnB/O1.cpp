#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010

vector<int> gr[MAXN];
int val[MAXN];
int val1[MAXN];
int beg[MAXN], last[MAXN], dfs_num = 0;
void dfs(int u){
	beg[u] = ++dfs_num;
	for(int i = 0; i < gr[u].size(); i++)
		dfs(gr[u][i]);
	last[u] = dfs_num;
}

int main(){
	int N, aux, S = 1000;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d %d", &aux, &val1[i]);
		if(aux)
			gr[aux].push_back(i);
	}
	dfs(1);

	for(int i = 1; i <= N; i++)
		val[beg[i]] = val1[i];
	for(int i = 1; i <= N; i++) val1[i] = val[i];
	for(int i = 1; i+S-1 <= N; i+=S)
		sort(val1+i, val1+i+S);

	int type, i, y;
	while( scanf("%d %d %d", &type, &i, &y) != EOF ){
		if(type == 1){
			i = beg[i];
			int ult = val[i];
			val[i] = y;
			int j = ((i-1)/S)*S + 1;
			int j1 = min(N, j+S-1);
			int l;
			for(l = j; val1[l] != ult; l++) ;
			val1[l] = val[i];
			for(; l+1 <= j1 && val1[l+1] < val1[l]; l++) swap(val1[l], val1[l+1]);
			for(; l-1 >= j && val1[l-1] > val1[l]; l--) swap(val1[l], val1[l-1]);
		}
		else{
			
			int ans = 0;
			int j = beg[i], j1 = last[i];

			int aux = ((j-1)/S + 1)*S;
			for(; j <= j1 && j <= aux; j++)
				ans += (int)(val[j] <= y);
			for(; j + S - 1 <= j1; j += S)
				ans += (int)(upper_bound(val1+j, val1 + j + S, y) - (val1 + j));
			for(; j <= j1; j++)
				ans += (int)(val[j] <= y);

			printf("%d\n", ans);
		}
	}
}