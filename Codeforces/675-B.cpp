//   Author : Misael Mateus 
//   Submission date: 2016-05-16 21:43:10
#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define four pair<ii, ii>
#define ll long long
int main()
{
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	ll cont = 0LL;
	for(ll x = 1; x <= n; x++)
	{
		ll w = x + a - d;
		ll k = x + (a + b) - (c + d);
		ll y = x + (b - c);
		if(w >= 1 && w <= n && k >= 1 && k <= n && y >= 1 && y <= n ){
			cont++;
		}
	}
	cout << cont*n;
	
	return 0;
}
