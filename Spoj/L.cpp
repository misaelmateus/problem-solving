#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define P 95542721LL

ll tree[MAXN*3][48];
ll v[MAXN*3];
ll aux[48];
int mark[MAXN*3];

void build(int i, int j, int n){
	if(i == j){
		tree[n][0] = v[0];
		for(int l = 1; l < 48; l++){
			tree[n][l] = (v[l] * 3LL) % P;
		}
		return ;
	}
	int mid = (i + j) >> 1;
	build(i, mid, n << 1);
	build(mid+1, j, (n << 1) | 1);
	for(int l = 0; l < 48; l++)
		tree[n][l] = (tree[n << 1][l] + tree[(n << 1) | 1][l]) % P;
}
void lazy(int n){
	if(!mark[n]) return ;
	memset(aux, 0, sizeof(aux));
	for(int l = 0; l < 48; l++)
		aux[(l + mark[n]) % 48] = tree[n][l];
	for(int l = 0; l < 48; l++)
		tree[n][l] = aux[l];

	if((n << 1) < 3*MAXN - 1){
		mark[n << 1] += mark[n];
		mark[(n << 1) + 1] += mark[n];
	}

	mark[n] = 0;
}

void update(int l, int r, int i, int j, int n){
	lazy(n);
	if(i > r || j < l) return ;
	if(i >= l && j <= r) {
		mark[n]++;
		lazy(n);
		return ;
	}
	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1);
	update(l, r, mid+1, r, (n << 1) + 1);
	for(int l = 0; l < 48; l++)
		tree[n][l] = (tree[n << 1][l] + tree[(n << 1) | 1]) % P;
}

ll sum(int l, int r, int i, int j, int n){
	if(i > r || j < l) return 0LL;
	lazy(n);
	if(i >= l && j <= r) {
		return tree[n][0];
	}
	int mid = (i + j) >> 1;
	return (sum(l, r, i, mid, n << 1) + sum(l, r, mid+1, r, (n << 1) + 1)) % P;
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	build(1, n, 1);
	int q;
	scanf("%d", &q);
	while(q--){
		int type, a, b;
		scanf("%d %d %d", &type, &a, &b);
		if(type == 1){
			printf("%lld\n", sum(a, b, 1, n, 1));
		}
		else update(a, b, 1, n, 1);
	}
}