#include<bits/stdc++.h>
#define MAXN 4010
using namespace std;

int tree[MAXN][MAXN];

void update(int i, int j, int k){
	while(j < MAXN){
		tree[i][j] += k;
		j += (j & -j);
	}
}

int query(int i, int j){
	int ans = 0;
	while(j > 0){
		ans += tree[i][j];
		j -= (j & -j);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	int n, a, b, r;
	cin >> n;

	while(n--){
		cin >> a >> b >> r;
		a += MAXN/2, b+= MAXN/2;
		for(int i = max(1, a-r); i <= min(MAXN-1, a+r); i++){
			int t = round(sqrt(r*r - (i - a)*(i - a)));
			if((i - a) * (i - a) + t*t > r*r) t--;
			//cout << t << endl;
			update(i, max(1, b-t), 1);
			update(i, b+t+1, -1);
		}
	}
	int cont = 0;
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++)
			cont = max(cont, query(i, j));
	}

	cout << cont << "\n";
}