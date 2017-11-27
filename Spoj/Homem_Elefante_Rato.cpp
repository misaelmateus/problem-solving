#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
int tree[MAXN*3][3];
int mark[MAXN * 3];
int v[MAXN];

void build(int l, int r, int n){
	if(l == r){
		tree[n][0] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, n << 1);
	build(mid+1, r, (n << 1) + 1);
	for(int k = 0; k < 3; k++)
		tree[n][k] = tree[(n << 1) + 1][k] + tree[n << 1][k];
}
void lazy(int n){
	if(!mark[n]) return ;
	mark[n] %= 3;
	int aux[3];
	for(int l =0; l < 3;l++){
		aux[l] = tree[n][(l - mark[n] + 3) % 3];
	}
	for(int l =0; l < 3;l++){
		tree[n][l] = aux[l];
	}
	if( (n << 1) < 3*MAXN - 1){
		mark[n << 1] += mark[n];
		mark[(n << 1) + 1] += mark[n];
	}
	mark[n] = 0;
}

void update(int l, int r, int i, int j, int n){
	lazy(n);
	if(i > r || j < l) return ;
	if(i >= l && j <= r){
		mark[n]++;
		lazy(n);
		return ;
	}

	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1);
	update(l, r, mid+1, j, (n << 1) + 1);
	for(int k = 0; k < 3; k++)
		tree[n][k] = tree[n << 1][k] + tree[(n << 1) + 1][k];
}

int query(int l, int r, int i, int j, int n, int p){
	if(i > r || j < l) return 0;
	lazy(n);
	if(i >= l && j <= r) return tree[n][p];
	int mid = (i + j) >> 1;
	return query(l, r, i, mid, n << 1, p) + query(l, r, mid+1, j, (n << 1) + 1, p);
}
int main(){
	int N, Q;
	while(scanf("%d %d", &N, &Q) != EOF){
		memset(tree, 0, sizeof(tree));
		memset(mark, 0, sizeof(mark));
		build(1, N, 1);	
		while(Q--){
			int x, y;
			char type;
			scanf(" %c %d %d", &type, &x, &y);

			if(type == 'C'){
				printf("%d %d %d\n", query(x, y, 1, N, 1, 0), query(x, y, 1, N, 1, 1), query(x, y, 1, N, 1, 2));
			}
			else{
				update(x, y, 1, N, 1);
			}
		}
		printf("\n");
	}
}