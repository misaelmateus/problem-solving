#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
int main(){
	int n;
	cin >> n;
	ll sum = 0LL;
	ll ans = 0LL;
	ll mult = 1LL;
	for(int i = 0; i < n-1; i++)
		mult = (mult * 2) % MOD;
	while(n--){
		ll a;
		cin >> a;
		sum = (sum + a) % MOD;
		ans = (ans +mult * a) %MOD;
	}
	ans = (ans - sum + MOD) % MOD;
	cout << ans << endl;
	return 0;
}