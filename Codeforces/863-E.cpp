//   Author : Misael Mateus 
//   Submission date: 2017-09-22 20:30:37
#include<bits/stdc++.h>
#define MAXN 2000100
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
int tree[MAXN*4];
int lazy[MAXN*4];

map<int, int> compressed;
set<int> aux;
pair<ii, int> tv[MAXN];

void propagate(int n){
	tree[n] += lazy[n];
	lazy[n << 1] += lazy[n];
	lazy[(n << 1) | 1] += lazy[n];
	lazy[n] = 0;
}

void update(int l, int r, int i, int j, int n){
	propagate(n);
	if(i > r || j < l) return ;
	//cout << i <<" " << j << " " << n << endl;
	if(i >= l && j <= r) {
		lazy[n]++;
		propagate(n);
		return;
	}
	int mid = (i + j) >> 1;
	update(l, r, i, mid, n << 1);
	update(l, r, mid+1, j, (n << 1) | 1);
	tree[n] = min(tree[n << 1], tree[(n << 1) | 1]);
}

int query(int l, int r, int i, int j, int n){
	propagate(n);
	if(i > r || j < l) return 1e9;
	if(i >= l && j <= r) {
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return min(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) | 1) );
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &tv[i].ff.ff, &tv[i].ff.ss), tv[i].ss = i+1;
		aux.insert(tv[i].ff.ff);
		aux.insert(tv[i].ff.ff-1);
		aux.insert(tv[i].ff.ff+1);
		aux.insert(tv[i].ff.ss);
		aux.insert(tv[i].ff.ss-1);
		aux.insert(tv[i].ff.ss+1);
	}
	int k = 1;
	for(auto u : aux){
		compressed[u] = k++;
	}
	for(int i = 0; i < n; i++){
		update(compressed[tv[i].ff.ff], compressed[tv[i].ff.ss], 1, MAXN-1, 1);
	}
	for(int i = 0; i < n; i++){
		if(query(compressed[tv[i].ff.ff], compressed[tv[i].ff.ss], 1, MAXN-1, 1) > 1){
			printf("%d\n", tv[i].ss);
			return 0;
		}

	}

	printf("-1\n");
	return 0;
}