#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;

ll tree[3*MAXN];
int flag[3*MAXN];
ll sum[3*MAXN][8];
ll v[MAXN];

ll Sqrt(ll a){
	ll x = sqrt(a);
	for( ; x*x > a; x--);
	for(; x*x <= a; x++);
	x--;
	return x;
}
void build(int i, int j, int n){
	if(i == j){
		for(int l = 0; l < 8; l++){
			sum[n][l] = v[i];
			v[i] = Sqrt(v[i]);
		}
		tree[n] = sum[n][0];
		return;
	}
	int mid = (i + j) >> 1;
	build(i, mid, (n << 1));
	build(mid+1, j, (n << 1)+1);
	for(int l = 0; l < 8; l++)
		sum[n][l] = sum[n << 1][l] + sum[(n << 1) + 1][l];
	tree[n] = sum[n][0];
	//cout << tree[n] << endl;
}

void lazy(int i, int j, int n){
	if(!flag[n]) return;
	for(int l = 0; sum[n][l] != j - i + 1 && l < 8; l++){
		sum[n][l] = sum[n][min(7, l+flag[n])];
	}
	tree[n] = sum[n][0];

	if( (n << 1) < 3*MAXN-1){
		flag[n << 1] += flag[n];
		flag[(n << 1) + 1] += flag[n];
	}
	flag[n] = 0;
}

void update(int l, int r, int i, int j, int n){
	if(i > r || j < l) return ;
	if(i >= l && j <= r){
		flag[n]++;
		lazy(i, j, n);
		return ;
	}
	lazy(i, j, n);
	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1);
	update(l, r, mid+1, j, (n << 1) + 1);
	for(int k = 0; sum[n][k] != j - i + 1 && k < 8; k++)
		sum[n][k] = sum[n << 1][k] + sum[(n << 1) + 1][k];
	tree[n] = sum[n][0];
}

ll query(int l, int r, int i, int j, int n){
	if(i > r || j < l) return 0LL;
	lazy(i, j, n);
	if(i >= l && j <= r){
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return query(l, r, i, mid, n << 1) + query(l, r, mid+1, j, (n << 1) + 1);
}
int main(){
	int N, k = 1;
	while(scanf("%d", &N) != EOF){
		memset(flag, 0, sizeof(flag));
		memset(sum, 0, sizeof(sum));
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= N; i++)
			scanf("%lld", &v[i]);
		build(1, N, 1);
		
		printf("Case #%d:\n", k++);
		
		int Q;
		scanf("%d", &Q);
		while(Q--){
			int type, x, y;
			scanf("%d %d %d", &type, &x, &y);
			if(x > y) swap(x, y);
			if(!type)
				update(x, y, 1, N, 1);
			else {
				ll ans = query(x, y, 1, N, 1);
				printf("%lld\n", ans);
			}
		}
		printf("\n");
	}
}