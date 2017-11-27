//   Author : Misael Mateus 
//   Submission date: 2017-10-06 18:51:14
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll unsigned long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;




int main(){
	readFast;
	ll a, b;
	cin >> a >> b;
	if(b > a + 20){
		cout << "0\n";
		return 0;
	}
	ll ans = 1ULL;
	for(ll i = b; i > a; i--){
		ans = (ans*i) % 10ULL;
	}

	cout << ans << "\n";
	return 0;
}