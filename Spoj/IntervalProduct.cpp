#include<bits/stdc++.h>
#define MAXN 100100
int tree[MAXN][2];
int v[MAXN];
void update(int k, int l, int val = 1){
	while(k < MAXN){
		tree[k][l] += val;
		k += (k & -k);
	}
}

int sum(int k, int l){
	int ans = 0;
	while(k > 0){
		ans += tree[k][l];
		k-= (k & -k);
	}
	return ans;
}

int sum(int a, int b, int l){
	return sum(b, l) - sum(a-1, l);
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			if(!v[i]) update(i, 0);
			else if(v[i] < 0) update(i, 1);
		}

		while(m--){
			char c;
			int a, b;
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'P'){
				if(sum(a, b, 0)) printf("0");
				else if(sum(a, b, 1) % 2 != 0) printf("-");
				else printf("+");
			}
			else {
				if(!v[a]) update(a, 0, -1);
				else if(v[a] < 0) update(a, 1, -1);
				v[a] = b;
				if(!v[a]) update(a, 0);
				else if(v[a] < 0) update(a, 1);
			}
		}
		printf("\n");
	}
}