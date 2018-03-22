#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fat(ll n, int k, ll l){
	if(!n) return 0;
	if(!k || n == 1) return 1LL;
	if(k & 1) return (n * fat(n, k-1, l))%l;
	return fat((n*n) % l, k/2, l);
}
int main(){
	ll n, ans;
	ll l = 500000003;
	cin >> n;
	cout << fat(3, fat(3, n % 250000001, l), 1000000007LL);
	return 0;
}