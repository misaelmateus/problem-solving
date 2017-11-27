#include<bits/stdc++.h>
#define MAXVAL 1000100
using namespace std;

struct vertex {
	vertex * l, * r;
	int sum;
 
	vertex (int val)
		: l(NULL), r(NULL), sum(val)
	{ }
 
	vertex (vertex * l, vertex * r)
		: l(l), r(r), sum(0)
	{
		if (l)  sum += l->sum;
		if (r)  sum += r->sum;
	}
};
 
vertex * build (int tl, int tr) {
	if (tl == tr)
		return new vertex (0);
	int tm = (tl + tr) / 2;
	return new vertex (
		build (tl, tm),
		build (tm+1, tr)
	);
}
 
int get_sum (vertex * t, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && tr == r)
		return t->sum;
	int tm = (tl + tr) / 2;
	return get_sum (t->l, tl, tm, l, min(r,tm))
		+ get_sum (t->r, tm+1, tr, max(l,tm+1), r);
}
 
vertex * update (vertex * t, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		return new vertex (new_val);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return new vertex (
				update (t->l, tl, tm, pos, new_val),
				t->r
			);
	else
		return new vertex (
				t->l,
				update (t->r, tm+1, tr, pos, new_val)
			);
}


int last_occurrence[MAXVAL];
int main(){
	int n;
	scanf("%d", &n);
	int v[n+1];
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);


	vertex * seg[n+1];
	seg[0] = build(1, n);

	for(int i = 1; i <= n; i++){
		vertex * aux = update(seg[i-1], 1, n, i, 1);
		if(last_occurrence[v[i]] == 0){
			seg[i] = aux;
			last_occurrence[v[i]] = i;
		}
		else{
			seg[i] = update(aux, 1, n, last_occurrence[v[i]], 0);
			last_occurrence[v[i]] = i;
		}

	}

	int q;
	scanf("%d", &q);
	while(q--){
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", get_sum(seg[b], 1, n, a, b));
	}
}