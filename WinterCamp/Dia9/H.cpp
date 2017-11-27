#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
using namespace std;
int main(){
	vector< pair<int, ll> > v1, v2; 
	vector<ll> su1;
	int n, b;
	cin >> n >> b;
	vector<ii> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	for(int mask = 0; mask < (1 << (n/2); mask++)){
		ll val = 0LL;
		int max = 0;
		
		for(int i = (n/2); i < ; i++){

		}
	}

	return 0;
}