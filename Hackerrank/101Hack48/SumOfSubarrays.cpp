#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ull a[n];
	ull ans = 0ULL;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ull sum1, sum2;
	for(int i = 0; i < n; i++){
		ull ma = 0, me = 0ULL - 1ULL;
		for(int j = i; j < n; j++){
			ma = max(ma, a[j]);
			me = min(me, a[j]);
			ans += (ma - me)*(ma - me);
		}
	}

	cout << ans << "\n";
}