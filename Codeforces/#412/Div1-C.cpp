// Code from Misael Mateus in Codeforces Round #412
#include<bits/stdc++.h>
#define MAXL 42
#define MAXN 100010
#define ll long long
using namespace std;

ll dp[MAXN][MAXL];
ll a[MAXL];
ll n[MAXL];

int calc(int i, int j, int min_k, int max_k){
	dp[i][j] = (1LL << 40 );
	int opt = 0;
	for(int k = min_k; k<= max_k && k <= n[j] && k <= i; k++){
		if(dp[k][j+1] + n[j] - k + a[j] <= i && dp[k][j+1] + n[j] - k + a[j] < dp[i][j]){
			dp[i][j] = dp[k][j+1] + n[j] - k + a[j];
			opt = k;
		}
	}
	return opt;
}

// Divide and Conquer optimization of dp
void sol(int min_N, int max_N, int K, int min_i,int max_i){
	if(max_N < min_N)
		return;
  	 int mid = (min_N + max_N)/2;
     int opt = calc(mid, K, min_i, max_i);
     if(min_N == max_N) return;
     sol(min_N, mid-1,K,  min_i, opt);
     sol(mid+1, max_N, K,  opt, max_i);
 }
int main(){
	ios::sync_with_stdio( false );
	int N;
	cin >> N;
	ll atual = 1LL;
	ll cont = 0;
	ll cont1 = 0;
	int i = 0;
	ll aux;
	while(N--){
		cin >> aux;
		if(aux > atual){
			a[i] += cont1;
			n[i] += cont;
			while(aux > atual) atual *= 2LL, i++;
			cont = cont1 = 0;
			if(aux == atual)
				cont++;
			else cont1++;
			continue;
		}
		if(aux == atual)
			cont++;
		else cont1++;
	}
	a[i] += cont1;
	n[i] += cont;
	
	for(int j = MAXL-2; j >= 1; j--) sol(0, MAXN-1, j, 0, MAXN-1);
	int tot = 0;
	for(int i = 1; i <= n[0]; i++){
		if(dp[i][1] <= 2*i - n[0]){
			cout << i << " ";
			tot++;
		}
	}
	if(!tot) cout << -1;
	cout << "\n";

	return 0;
}	