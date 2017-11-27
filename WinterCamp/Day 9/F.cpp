#include<bits/stdc++.h>
#define ll long long
#define MAXN 400100
using namespace std;
ll A[MAXN];
ll sumArray;
ll n;
ll h1;
ll height(ll x){
	ll sum1 = sumArray*(x);
	return sum1;
}

ll h(ll x){
	return h1 - x*(x+1)/2;
}
int main(){
	ios::sync_with_stdio(false);	
	cin >> n >> h1;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		sumArray += A[i];
	}
	ll ans = (1LL << 32);
	ll sum1 = 0LL;
	for(ll l = 0; l < n; l++){
		sum1 += A[l];
		ll i = -1, j = (2e9)/n + 1;
		while(j - i > 1){
			ll middle = (i + j) >> 1;
			//cout << middle << " " << height(middle) << " " << h(middle) << endl;
			if(sum1 + height(middle) >= h(middle*n + l + 1))
				j = middle;
			else i = middle;
		}
		if(sum1 + height(j) >= h(j*n + l + 1))
			ans = min(ans, j*n + l + 1);
		
	}
	cout << ans << "\n";
}