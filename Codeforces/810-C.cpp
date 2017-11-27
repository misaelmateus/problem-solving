//   Author : Misael Mateus 
//   Submission date: 2017-05-20 23:53:22
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 0.000000001
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++);
#define rep(a, b) fr(a, 0, c)
#define fill(v, x) memset(v, x, sizeof(v))
#define RI(x) scanf("%d", &x)
#define RII(x, y) scanf("%d %d", &x, &y)
#define L 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll a[n+1];
	ll pot2[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	pot2[0] = 1;
	for(int i = 1; i <= n; i++){
		pot2[i] = (pot2[i-1]*2)%L;
	}

	ll ans = 0LL;
	for(int j = 1; j <= n; j++){
		ans = (ans + a[j]*(pot2[j-1] - pot2[n-j]))%L;
	}

	cout << ans << "\n";
}