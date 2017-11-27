#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int tree[MAXN*4];
int treeMark[MAXN*4];
int mark[MAXN*4];
int lazy[MAXN*4];
int p[MAXN];
void push(int n){
	if(!mark[n]) return;
	treeMark[n] ^= mark[n] & 1;
	tree[n] = lazy[n] - tree[n];
	
	lazy[n << 1] = lazy[n] - lazy[n << 1];
	mark[n << 1] += mark[n];
	lazy[n << 1 | 1] = lazy[n] - lazy[n << 1 | 1];
	mark[n << 1 | 1] += mark[n];
	
	mark[n] = lazy[n] = 0;
}

void update(int l, int r, int i, int j, int n, int k){
	push(n);
	if(i > r || j < l) return ;
	if(i >= l && j <= r ){
		mark[n]++;
		lazy[n] =  k - lazy[n];
		push(n);
		return ;
	}
	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1, k);
	update(l, r, mid+1, j, n << 1 | 1, k);
}

int query(int pos, int i, int j, int n){
	push(n);
	if(i > pos || j < pos) return 0;
	if(i == j && i == pos){
		return tree[n] + (treeMark[n] == 0) * p[i] - (treeMark[n] == 1)*p[i];
	}
	int mid = (i + j) >> 1;
	if(mid+1 > pos)
		return query(pos, i, mid, n << 1);
	return query(pos, mid+1, j, n << 1 | 1);
}

void clean(){
	memset(mark, 0, sizeof(mark));
	memset(treeMark, 0, sizeof(treeMark));
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
}
int main(){
	int n;
	while(scanf("%d", &n) && n){
		clean();
		int aux;
		for(int i = 1; i <= n; i++){
			scanf("%d", &aux);
			p[aux] = i;
		}

		for(int i = 1; i <= n; i++){
			int pos = query(i, 1, n, 1);
			if(i) printf(" ");
			printf("%d", pos);

			update(i, pos, 1, n, 1, pos + i);
		}

	}
}