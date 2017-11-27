#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
using namespace std;




int main(){
	ios::sync_with_stdio(false);	
	int T;
	cin >> T;
	while(T--){
		int k, a, b;
		cin >> k >> a >> b;
		int ans = min(abs(a- b), k - abs(a- b)) - 1;
		if(k % 2 == 0 && ans == k/2 - 1) cout << 0 << "\n";
		else cout << ans << "\n";
	}	

	return 0;
}