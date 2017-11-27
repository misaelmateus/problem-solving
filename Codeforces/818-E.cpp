//   Author : Misael Mateus 
//   Submission date: 2017-06-30 23:04:28
#include<bits/stdc++.h>
#define ll long long
#define MAXN 400010
using namespace std;

ll tree[MAXN];
ll K;

ll update(int l, int r, int i, int n, ll k){
	if(i < l || i > r)
		return tree[n];
	if(l == r){
		return tree[n] = k % K;
	}
	int middle = (l + r) >> 1;
	return tree[n] = (update(l, middle, i, 2*n, k) * update(middle+1, r,i,  2*n+1, k)) % K;

}

ll mult(int l, int r, int i, int j, int n){
	if(r < i || l > j)
		return 1LL;
	if(l >= i && r <= j)
		return tree[n];
	int middle = (l + r) >> 1;
	return (mult(l, middle, i, j, 2*n) * mult(middle +1, r, i, j, 2*n+1)) % K;
}
int main(){
	ios::sync_with_stdio(false);	
	ll n;
	cin >> n >> K;
	for(int i = 1; i <= n; i++){
		ll aux;
		cin >> aux;

		update(1, n, i, 1, aux);
	}
	ll ans = 0LL;
	
	for(int p = 1; p <= n; p++){
		int i = p-1, j = n;
		while(j - i > 1){
			int middle = (i + j) >> 1;
			if(mult(1, n, p, middle, 1) == 0)
				j = middle;
			else i = middle;
		}
		if(mult(1, n, p, j, 1) != 0)
			continue;
		ans += (ll)(n - j + 1);

	}

	cout << ans << endl;

	return 0;
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 400010
using namespace std;

ll tree[MAXN];
ll K;

ll update(int l, int r, int i, int n, ll k){
	if(i < l || i > r)
		return tree[n];
	if(l == r){
		return tree[n] = k % K;
	}
	int middle = (l + r) >> 1;
	return tree[n] = (update(l, middle, i, 2*n, k) * update(middle+1, r,i,  2*n+1, k)) % K;

}

ll mult(int l, int r, int i, int j, int n){
	if(r < i || l > j)
		return 1LL;
	if(l >= i && r <= j)
		return tree[n];
	int middle = (l + r) >> 1;
	return (mult(l, middle, i, j, 2*n) * mult(middle +1, r, i, j, 2*n+1)) % K;
}
int main(){
	ios::sync_with_stdio(false);	
	ll n;
	cin >> n >> K;
	for(int i = 1; i <= n; i++){
		ll aux;
		cin >> aux;

		update(1, n, i, 1, aux);
	}
	ll ans = 0LL;
	
	for(int p = 1; p <= n; p++){
		int i = p-1, j = n;
		while(j - i > 1){
			int middle = (i + j) >> 1;
			if(mult(1, n, p, middle, 1) == 0)
				j = middle;
			else i = middle;
		}
		if(mult(1, n, p, j, 1) != 0)
			continue;
		ans += (ll)(n - j + 1);

	}

	cout << ans << endl;

	return 0;
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 400010
using namespace std;

ll tree[MAXN];
ll K;

ll update(int l, int r, int i, int n, ll k){
	if(i < l || i > r)
		return tree[n];
	if(l == r){
		return tree[n] = k % K;
	}
	int middle = (l + r) >> 1;
	return tree[n] = (update(l, middle, i, 2*n, k) * update(middle+1, r,i,  2*n+1, k)) % K;

}

ll mult(int l, int r, int i, int j, int n){
	if(r < i || l > j)
		return 1LL;
	if(l >= i && r <= j)
		return tree[n];
	int middle = (l + r) >> 1;
	return (mult(l, middle, i, j, 2*n) * mult(middle +1, r, i, j, 2*n+1)) % K;
}
int main(){
	ios::sync_with_stdio(false);	
	ll n;
	cin >> n >> K;
	for(int i = 1; i <= n; i++){
		ll aux;
		cin >> aux;

		update(1, n, i, 1, aux);
	}
	ll ans = 0LL;
	
	for(int p = 1; p <= n; p++){
		int i = p-1, j = n;
		while(j - i > 1){
			int middle = (i + j) >> 1;
			if(mult(1, n, p, middle, 1) == 0)
				j = middle;
			else i = middle;
		}
		if(mult(1, n, p, j, 1) != 0)
			continue;
		ans += (ll)(n - j + 1);

	}

	cout << ans << endl;

	return 0;
}#include<bits/stdc++.h>
#define ll long long
#define MAXN 400010
using namespace std;

ll tree[MAXN];
ll K;

ll update(int l, int r, int i, int n, ll k){
	if(i < l || i > r)
		return tree[n];
	if(l == r){
		return tree[n] = k % K;
	}
	int middle = (l + r) >> 1;
	return tree[n] = (update(l, middle, i, 2*n, k) * update(middle+1, r,i,  2*n+1, k)) % K;

}

ll mult(int l, int r, int i, int j, int n){
	if(r < i || l > j)
		return 1LL;
	if(l >= i && r <= j)
		return tree[n];
	int middle = (l + r) >> 1;
	return (mult(l, middle, i, j, 2*n) * mult(middle +1, r, i, j, 2*n+1)) % K;
}
int main(){
	ios::sync_with_stdio(false);	
	ll n;
	cin >> n >> K;
	for(int i = 1; i <= n; i++){
		ll aux;
		cin >> aux;

		update(1, n, i, 1, aux);
	}
	ll ans = 0LL;
	
	for(int p = 1; p <= n; p++){
		int i = p-1, j = n;
		while(j - i > 1){
			int middle = (i + j) >> 1;
			if(mult(1, n, p, middle, 1) == 0)
				j = middle;
			else i = middle;
		}
		if(mult(1, n, p, j, 1) != 0)
			continue;
		ans += (ll)(n - j + 1);

	}

	cout << ans << endl;

	return 0;
}