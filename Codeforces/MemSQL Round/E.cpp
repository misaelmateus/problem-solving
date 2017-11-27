#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

int gr[MAXN];


vector<int> s;
int tot;

int c[MAXN];
int count[MAXN];
int mark[MAXN];
int cycle[MAXN];
int k;

void dfs(int u){
	mark[u] = 1;
	if(gr[u] == u) return;
	if(mark[gr[u]] == 0){
		dfs(gr[u]);
	}
	else if(mark[gr[u]] == 1){
		k++;
		cycle[u] = 1;
		tot--;
	}
	if(cycle[gr[u]])
		tot--;
	mark[u] = 2;
}

int main(){
	int N, a, b;
	scanf("%d", &N);
	tot = N;
	for(int i = 0; i < N; i++){
		scanf("%d %d", &a, &b);
		gr[a] = b;
	}

	for(int i = 1; i <= 2*N; i++){
		if(gr[a] != 0 && !mark[i]){
			dfs(i);
		}
	}
	cout << tot << endl << k << endl;
	printf("%d\n", tot + (1 << k));

}