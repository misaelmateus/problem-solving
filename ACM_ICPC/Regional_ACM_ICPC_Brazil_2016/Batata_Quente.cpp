#include<bits/stdc++.h>
#define MAXN 100010
#define vi vector<int>
using namespace std;

int mark[MAXN];
int p[MAXN];
int val[MAXN];



void dfs2(int u, int x){
	val[u] = x;
	if(!mark[p[u]]) dfs2(p[u], x);
}
int dfs(int u){
	if(val[u] != -1){
		return val[u];
	}
	val[u] = 100000000;
	if(val[p[u]] == 100000000)
		mark[p[u]] = 1, val[u] = u;
	else val[u] =  min(u, dfs(p[u]));
	if(mark[u])
		dfs2(u, val[u]);
	return val[u];
}

vi tree[MAXN*4];
void build(int i, int j, int n){
	for(int l = i; l <= j; l++){
		tree[n].push_back(val[l]);
	}
	sort(tree[n].begin(), tree[n].end());
	if(i == j) return;
	int middle = (i + j) >> 1;
	build(i, middle, 2*n);
	build(middle+1, j, 2*n+1);
}

int query(int a, int b, int i, int j, int k, int n){
	if(i > b || j < a) return 0;
	if(i >= a && j <= b)
		return (int)(upper_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin());
	int middle = (i + j) >> 1;
	return query(a, b, i, middle, k, 2*n) + query(a, b, middle+1, j, k, 2*n+1);
}


int main(){
	memset(val, -1, sizeof(val));
	int N, Q;
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= N; i++){
		dfs(i);
	}

	build(1, N, 1);
	while(Q--){
		int a, b;
		scanf("%d %d", &a, &b);
		int ans, ans1;
		int i = 1, j = N+1;
		while(j - i > 1){
			int middle = (i+j) >> 1;
			int x = query(a, b, 1, N, middle, 1);
			if(x <= (b - a + 1)/2)
				i = middle;
			else
				j = middle;
		}
		ans = query(a, b, 1, N, i, 1);
		j = i, i = 0;
		while(j - i > 1){
			int middle = (i+j) >> 1;
			int x = query(a, b, 1, N, middle, 1);
			if( x == ans)
				j = middle;
			else
				i = middle;
		}

		int i1 = 0, j1 = N;
		while(j1 - i1 > 1){
			int middle = (i1+j1) >> 1;
			int x = query(a, b, 1, N, middle, 1);
			if(x >= (b - a + 1)/2)
				j1 = middle;
			else
				i1 = middle;
		}
		if(abs(b-a+1 - 2*query(a, b, 1, N, j, 1)) <= abs(b-a+1 - 2*query(a, b, 1, N, j1, 1)))
			printf("%d\n", j);
		else
			printf("%d\n", j1);
	}

}