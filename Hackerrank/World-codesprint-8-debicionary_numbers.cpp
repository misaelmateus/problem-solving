#include<bits/stdc++.h> 
#define ll long long
ll dp[10][20000010];
int reduce[40000010];
int leftmost[40000010];
void re(int x){
	int i = leftmost[x-1] + 1;
	for(; i >= 0 && !(x & (1LL << i)); i--);
	reduce[x] = x - (1LL << i);
	leftmost[x] = i;
}
ll f(ll x, int n){
	if(x < 0 || x > 9 ) return 0;
	if(n < 20000010 && dp[x][n]) return dp[x][n];
	if(n == 0)
		return 1LL;
	ll ans = 0LL;
	int n1 = reduce[n];
	for(int i = 0; i <= x; i++){
		ans += f(2*i + 1, n1);
	}
	if(n >= 20000010)
		return ans;
	return dp[x][n] = ans;
}
using namespace std;
int main(){
	for(int i = 1; i < 40000000; i++) re(i);
	ll ans = 0;
	for(int i = 1; i < 40000000; i++){
		ans += f(0, i);
	}
	cout << ans << endl;
}