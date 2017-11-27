//   Author : Misael Mateus 
//   Submission date: 2017-11-26 21:57:55
#include<bits/stdc++.h>
#define MAXN 100100
#define ll long long
#define P 1000000007
using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int cont[100];	
vector<int> fact[100];
ll dp[50][1 << 19];
ll C[MAXN];
int main(){
	C[0] = 1;
	C[1] = 1;
	for(int i = 2; i < MAXN; i++)
			C[i] = (C[i-1]*2) % P;
	int n;
	scanf("%d", &n);
	int aux;
	for(int i = 0; i < n; i++){
		scanf("%d", &aux);
		int num = 1;
		for(int j = 0; j < 19; j++){
			int q = 0;
			while(aux % primes[j] == 0)
				aux /= primes[j], q++;
			q %= 2;
			if(q) num *= primes[j];
		}
		cont[num]++;
	}
	vector<int> a;
	for(int i = 2; i < 100; i++){
		if(!cont[i]) continue;
		a.push_back(i);
		for(int j = 0; j < 19; j++)
			if(i % primes[j] == 0)
				fact[i].push_back(j);
	}
	ll ans = 1LL;
	for(int i = 0; i < cont[1]; i++)
		ans = (ans * 2) % P;
	if(a.size() == 0){
		ans = (ans + P-1) % P;
		printf("%lld\n", ans);
		return 0;
	}
	dp[0][0] = C[cont[a[0]]];
	int mask = 0;
	for(int i = 0; i < fact[a[0]].size(); i++)
		mask ^= 1 << fact[a[0]][i];
	dp[0][mask] = C[cont[a[0]]];

	for(int i = 1; i < a.size(); i++){
		for(int j = 0; j < (1 << 19); j++){
			dp[i][j] = (dp[i-1][j]*C[cont[a[i]]]);
			mask = 0;
			for(int l = 0; l < fact[a[i]].size(); l++)
				mask ^= 1 << fact[a[i]][l];
			dp[i][j] += (dp[i-1][j^mask] * C[cont[a[i]]]);
			dp[i][j] %= P;
		}
	}
	ans = ((ans * dp[a.size()-1][0] + P - 1) % P);
	printf("%lld\n", ans);
}