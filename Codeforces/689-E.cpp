//   Author : Misael Mateus 
//   Submission date: 2017-09-10 21:09:16
#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define MOD 1000000007LL
#define MAXN 200010
using namespace std;

int mdc(int  a, int b, int *x, int *y) {
  int xx, yy, d;
  if(b==0) {
    *x=1; *y=0;
    return a;
  }
 
  d = mdc(b, a%b, &xx, &yy);
  *x = yy;
  *y = xx - a/b*yy;
  return d;
}
 
 
int inv(int a){
  int x,y,d;
  d = mdc(a,MOD,&x,&y);
 
  if(x<0){
    x = x+MOD;
  }
 
  return x;
 
 
}

ll perm[MAXN];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	perm[k] = 1LL;
	for(ll i = k+1; i <= n; i++){
		perm[i] = (((i * perm[i-1]) % MOD) * inv(i - k)) % MOD;
	}
	
	multiset<ii> s;
	for(int i = 0; i < n; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		s.insert({l, 0});
		s.insert({r, 1});
	}
	int t = 0;
	int ult = 0;
	ll ans = 0LL;
	for(auto u: s){
		if(u.second == 0){
			ans = (ans + (ll)(u.first - ult) * perm[t]) % MOD;
			ult = u.first;
			t++;
		}
		else {
			ans = (ans + (ll)(u.first - ult + 1) *perm[t] ) % MOD;
			t--;
			ult = u.first+1;
		}
	}

	printf("%lld\n", ans);
}