//   Author : Misael Mateus 
//   Submission date: 2017-06-27 20:06:49
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, c)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define L 1000100

int cont[4*L];

void update(int p, int k){
	while(p < 4*L){
		cont[p] += k;
		p += (p & -p);
	}

}

int sum(int p){
	int sum = 0;
	while(p > 0){
		sum += cont[p];
		p -= (p & -p);
	}
	return sum;
}

int main(){
	int n;
	RI(n);
	int p[n+1];
	ll S = 0LL;
	for(int i = 1; i <= n; i++){
		RI(p[i]);
		update(p[i] - i + L, 1);
		S += (ll)abs(p[i] - i);

	}
	int best_x = 0;
	ll best_S = S;
	int x = 0;
	int y = n;

	for(; y > 1; y--){
		update(p[y] - y + L, -1);
		S = S - (ll)abs(p[y] - n) + (ll)abs(p[y] - 1);

		S = S + (ll)2*sum(x+L) - (ll)sum(4*L-1);
		x++;
		update(p[y] - 1 + x + L, 1);

		if(S < best_S){
			best_x = x;
			best_S = S;
		}
	}

	printf("%I64d %d\n", best_S, best_x);

	return 0;
}