#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;
ll Sqrt(ll a){
	ll x = sqrt(a);
	for( ; x*x > a; x--);
	for(; x*x <= a; x++);
	x--;
	return x;
}
set<int> s;
ll tree[MAXN];
ll v[MAXN];
void update(int k, ll val){
	while(k < MAXN)
	{
		tree[k] += val;
		k += (k & -k);
	}
}

ll query(int k){
	ll ans = 0;
	while(k > 0){
		ans += tree[k];
		k -= (k & -k);
	}
	return ans;
}

ll query(int a, int b){
	return query(b) - query(a-1);
}

int main(){
	int n, k = 1;
	while(scanf("%d", &n) != EOF){
		memset(tree, 0, sizeof(tree));
		s.clear();
		for(int i = 1; i <= n; i++){
			scanf("%lld", &v[i]);
			update(i, v[i]);
			if(v[i] > 1)
				s.insert(i);
		}
		printf("Case #%d:\n", k++);
		int q;
		scanf("%d", &q);
		while(q--){
			int type, a, b;
			scanf("%d %d %d", &type, &a, &b);
			if(a > b) swap(a, b);
			if(type){
				ll ans = query(a, b);
				printf("%lld\n", ans);
			}
			else{
				set<int>::iterator it = s.lower_bound(a);
				vector<int> er;
				while(it != s.end() && *it <= b){
					ll x = v[*it];
					v[*it] = Sqrt(v[*it]);
					update(*it, v[*it] - x);
					if(v[*it] == 1)
						er.push_back(*it);
					it++;
				}
				for(int i = 0; i < er.size(); i++) s.erase(er[i]);
			}
		}

		printf("\n");
	}

}
