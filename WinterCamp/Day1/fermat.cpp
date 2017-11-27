#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
using namespace std;
ll M;
ll exp(ll a, ll n){
	if(n == 0)
		return 1LL;
	if(n == 1)
		return a%M;
	ll b = exp(a, n/2);
	b = (b*b) % M;
	if(n & 1) b = (a*b) % M;

	return b;
}
int cont[300000];

int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	int resp = 0;
	
	fr(i, 1, M)
		cont[exp(i, n)]++;
	cout << resp << endl;
}