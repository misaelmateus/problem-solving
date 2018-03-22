#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
    return (b == 0LL) ? a : gcd(b, a % b);
}
int main(){
	int n;
	cin >> n;
	ll v[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];

	if(n == 1){
		cout << v[0] + 1 << endl;
		return 0;
	}
	ll l[n], r[n];
	l[0] = v[0];
	for(int i = 1; i < n; i++)
		l[i] = gcd(v[i], l[i-1]);

	l[n-1] = v[n-1];

	for(int i = n-2; i >= 0; i--)
		r[i] = gcd(r[i+1], v[i]);

	for(int i = 0; i < n; i++){
		ll ans;
		if(i == 0)
			ans = r[i+1];
		else if(i == n-1)
			ans = l[i-1];
		else ans = gcd(r[i+1], l[i-1]);
		if(v[i] % ans != 0)
		{
			cout << ans << endl;
			return 0;
		}
	}	

}