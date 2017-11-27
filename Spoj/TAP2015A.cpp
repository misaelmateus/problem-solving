#include<bits/stdc++.h>
#define MAXN 2010
using namespace std;
int M[MAXN*2][MAXN*2];
int main(){
	ios::sync_with_stdio( false );
	int N, a, b, r;
	cin >> N;

	while(N--){
		cin >> a >> b >> r;
		a += MAXN, b += MAXN;
		for(int i = max(0, a-r); i <= min(2*MAXN-1, a+r); i++){
			int t = sqrt(r*r - (i - a)*(i - a));
			while(t*t + (i- a)*(i-a) <= r*r) t++;
			t--;
			M[i][max(0, b - t)] += 1;
			M[i][min(2*MAXN-1, b+t+1)] += -1;
		}
	}
	int ans = 0;
	for(int i = 0; i < MAXN*2; i++){
		int val = 0;
		for(int j = 0; j < MAXN*2; j++)
			val += M[i][j], ans = max(ans, val);
	}

	cout << ans << "\n";
	return 0;
}