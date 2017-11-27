#include<bits/stdc++.h>
#define MAXN 200100
#define ll long long
using namespace std;
ll tree[MAXN*3];
int v[MAXN];


void build(int l ,int r, int n){
	if(l == r){
		tree[n] = v[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, n << 1);
	build(mid+1, r, (n << 1) | 1);
	tree[n] = tree[n << 1] & tree[(n << 1) | 1];
}

int query(int l, int r, int i, int j, int n){
	if(i > r || j < l) return (1 << 30) - 1;
	if(i >= l && j <= r)  {
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return query(l, r, i, mid, n << 1) & query(l, r, mid+1, j, (n << 1) | 1);
} 

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int N, K;
		scanf("%d %d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &v[i]);
		build(1, N, 1);
		for(int i = 1; i <= N; i++){
			if(K >= N)
				printf("%d ", query(1, N, 1, N, 1));
			else{
				printf("%d ", query(max(1, i - K), min(N, i + K), 1, N, 1)&query(1, i + K - N, 1, N, 1) & query(N - K + i, N, 1, N, 1));
			}
		}
		printf("\n");
	}
}