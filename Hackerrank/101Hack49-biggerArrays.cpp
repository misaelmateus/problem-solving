#include<bits/stdc++.h>
#define MAX 800000
#define ll long long
#define L 1000000007
using namespace std;
 
ll tree[MAX][2];
ll mark[MAX][2];

int fast_pot(ll x, ll p){
	if(p == 0)
		return 1;
	if(p == 1)
		return x % L;
	ll ans = fast_pot(x, p/2);
	ans = (ans * ans) % L;
	if(p % 2 != 0) ans = (ans * x) % L;
	return ans;
}
void propagate(ll n, ll i, ll j, int pos)
{
    if(mark[n][pos] == -1)
        return ;
    tree[n][pos] = fast_pot( mark[n][pos], (j - i + 1) ); // update tree
    
    // mark sons
    mark[2*n][pos] = mark[n][pos];
    mark[2*n+1][pos] = mark[n][pos];
    mark[n][pos] = -1;
}
void update(ll i, ll j, ll l, ll r, ll n, ll k, int pos)
{
    propagate(n, l, r, pos);
    if(l >= i && r <= j)
    {
        mark[n][pos] = k;
        propagate(n, l, r, pos); // update current
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k, pos);
    update(i, j, middle + 1, r, 2*n + 1, k, pos);
    
    tree[n][pos] = (tree[2*n][pos] * tree[2*n + 1][pos] ) %L; // update current
 
}
ll query(ll i, ll j, ll l, ll r, ll n, int pos)
{
    if(r < i || l > j)
        return 1;
    propagate(n, l, r, pos);
    if(l >= i && r <= j)
        return (ll) tree[n][pos];

    ll middle = (l + r) / 2;
    return (query(i, j, l, middle, 2*n, pos)* query(i, j, middle + 1, r, 2*n + 1, pos)) %L; // return according to the sons
}

int main(){
	memset(mark, -1, sizeof(mark));
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		update(i, i, 1, n, 1, x, 0);
		update(i, i, 1, n, 1, x-1, 1);
	}

	while(q--){
		int type, l, r;
		cin >> type >> l >> r;
		if(type == 1){
			int x;
			cin >> x;
			update(l, r, 1, n, 1, x, 0);
			update(l, r, 1, n, 1, x-1, 1);
		}
		else{
			ll ans = (query(l, r, 1, n, 1, 0) - query(l, r, 1, n, 1, 1))%L;
			if(ans < 0) ans += L;
			cout << ans << "\n";
		}
	}
}