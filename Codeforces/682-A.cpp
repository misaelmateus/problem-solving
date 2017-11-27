//   Author : Misael Mateus 
//   Submission date: 2016-06-17 23:19:49
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll n, m;
	cin >> n >> m;
	ll cont = 0LL;
	for(ll i = 1; i <= n; i++){
		ll k1 = i/5LL + (i % 5LL != 0);
		if(5LL * k1 - i == 0)
			k1++;
		ll k2 = (m + i)/5LL;
		if(k2 < k1)
			continue;
		cont += (k2 - k1 + 1);
	}

	cout << cont << endl;

	return 0;
}
