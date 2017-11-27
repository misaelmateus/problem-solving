#include<bits/stdc++.h>
#define ll long long
#define MAXN 200080
using namespace std;
#define T 77
ll M[MAXN/T];
ll v[MAXN];
int main(){
	ios::sync_with_stdio(false);	
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < MAXN/T; i++) M[i] = (1LL << 60);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int i = 0; i < n; i++)
		M[i/T] = min(v[i], M[i/T]);

	while(q--){
		ll k;
		int a, b;
		cin >> k >> a >> b;
		a--, b--;
		int i = a;
		for(; i <= b && i % T ; i++) 
			k = k % v[i];
		for(; i + T <= b+1 && k; i+= T) {
			if(M[i/T] > k) continue;
			for(int j = i; j < i+T; j++)
				k = k % v[j];
		}
		for(; i <= b && k; i++) k = k % v[i];
		cout << k << "\n";
	}

	return 0;
}