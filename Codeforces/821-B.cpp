//   Author : Misael Mateus 
//   Submission date: 2017-07-06 16:17:36
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	ll m, b;
	cin >> m >> b;	
	ll ans = 0LL;
	for(ll y = 0; y <= b; y++){
		ll x = m*(b - y);
		ans = max(x*(x+1)*(y+1)/2 + y*(y+1)*(x+1)/2, ans);
	}

	cout << ans << endl;

	return 0;


}