#include<bits/stdc++.h>
#define P 31
#define ll long long 
#define MAXN 30001
using namespace std;
ll h[MAXN];
ll h1[MAXN];
ll pot[MAXN];
int main(){
	ios::sync_with_stdio(false);
	int k, cont = 0;
	string s;
	cin >> k >> s;

	h[0] = (ll)s[0];
	h1[s.size()- 1] = (ll)s[s.size() - 1];
	pot[0] = 1LL;

	for(int i = 1; i < s.size(); i++)
		pot[i] = pot[i-1] * P, h[i] = h[i-1] + (ll)s[i] * pot[i];
	for(int i = s.size()-2; i >= 0; i--)
		h1[i] = h1[i+1] + (ll)s[i] * pot[s.size() - 1 - i];
	
	for(int i = 0; i + k <= s.size(); i++){
		ll a = h[i+k-1] - (i > 0? h[i-1] : 0);
		ll b = h1[i] - (i+k < s.size() ? h1[i+k] : 0);
		a *= pot[s.size() - (i + k)];
		b *= pot[i];
		if(a == b)
			cont++;
	}
	cout << cont << endl;
}