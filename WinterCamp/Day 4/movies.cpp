#include<bits/stdc++.h>
#define ll long long
#define MAXN 1000010
using namespace std;

ll tree[MAXN];

ll sum(int p){
	ll ans = 0LL;
	while(p > 0){
		ans += tree[p];
		p -= p & -p;
	}
	return ans;
}

void update(int p, ll k){
	while(p < MAXN){
		tree[p] += k;
		p += p & -p;
	}
}

int cont[MAXN];
int pos[MAXN];
int main(){
	ios::sync_with_stdio(false);	
	int p, f;
	cin >> p >> f;
	int a[p+1], v[f+1];
	for(int i = 1; i <= p; i++) cin >> a[i];
	for(int i = 1; i <= f; i++) cin >> v[i];
	ll ans = 0, aux = 0;
	int ult = 1;
	for(int i = 1; i <= p; i++){
		if(!cont[a[i]]){
			cont[a[i]]++;
			update(i, (ll)v[a[i]]);
			pos[a[i]] = i;
			ans = max(ans, sum(i));
		}
		else{
			ll x = sum(pos[a[i]]);
			if(v[a[i]] <= x){
				if(cont[a[i]] == 1){
					update(pos[a[i]], (ll)-v[a[i]]);
				}
				cont[a[i]]++;	
				pos[a[i]] = i;
			}
			else{
				for(int j = ult; j <= pos[a[i]]; j++) cont[a[j]] = 0;
				update(pos[a[i]], -sum(pos[a[i]]));
				update(i, (ll)v[a[i]]);
				ult = pos[a[i]]+1;
				pos[a[i]] = i;
				cont[a[i]] = 1;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}