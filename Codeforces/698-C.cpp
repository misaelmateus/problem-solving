//   Author : Misael Mateus 
//   Submission date: 2017-03-17 17:31:25
#include<bits/stdc++.h>
#define MAX 2097152
#define MAXN 21
#define ld double
using namespace std;

ld dp[MAX];
ld p[MAXN];
ld sum[MAX];
ld ans[MAXN];
int main(){
	int n, k;
	cin >> n >> k;
	int cont = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i] > 0.00000001) cont++;
	}
	k = min(k, cont);

	dp[0] = 1.;
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i))
				sum[mask] += p[i];
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)){
				int maski = mask - (1 << i);
				if(sum[maski] < 0.99999999)
					dp[mask] += dp[maski] / (1. - sum[maski]) * p[i];
			}
		}
	}
	
	for(int mask = 1; mask < (1 << n); mask++){
		cont = 0;
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)) cont++;
		}
		if(cont == k){
			for(int i = 0; i <= 20; i++)
				if(mask & (1 << i)) 
					ans[i] += dp[mask];
		}

	}
	for(int i = 0; i < n; i++)
		cout << fixed << setprecision(8) << ans[i] << " ";
}#include<bits/stdc++.h>
#define MAX 2097152
#define MAXN 21
#define ld double
using namespace std;

ld dp[MAX];
ld p[MAXN];
ld sum[MAX];
ld ans[MAXN];
int main(){
	int n, k;
	cin >> n >> k;
	int cont = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i] > 0.00000001) cont++;
	}
	k = min(k, cont);

	dp[0] = 1.;
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i))
				sum[mask] += p[i];
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)){
				int maski = mask - (1 << i);
				if(sum[maski] < 0.99999999)
					dp[mask] += dp[maski] / (1. - sum[maski]) * p[i];
			}
		}
	}
	
	for(int mask = 1; mask < (1 << n); mask++){
		cont = 0;
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)) cont++;
		}
		if(cont == k){
			for(int i = 0; i <= 20; i++)
				if(mask & (1 << i)) 
					ans[i] += dp[mask];
		}

	}
	for(int i = 0; i < n; i++)
		cout << fixed << setprecision(8) << ans[i] << " ";
}#include<bits/stdc++.h>
#define MAX 2097152
#define MAXN 21
#define ld double
using namespace std;

ld dp[MAX];
ld p[MAXN];
ld sum[MAX];
ld ans[MAXN];
int main(){
	int n, k;
	cin >> n >> k;
	int cont = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i] > 0.00000001) cont++;
	}
	k = min(k, cont);

	dp[0] = 1.;
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i))
				sum[mask] += p[i];
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)){
				int maski = mask - (1 << i);
				if(sum[maski] < 0.99999999)
					dp[mask] += dp[maski] / (1. - sum[maski]) * p[i];
			}
		}
	}
	
	for(int mask = 1; mask < (1 << n); mask++){
		cont = 0;
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)) cont++;
		}
		if(cont == k){
			for(int i = 0; i <= 20; i++)
				if(mask & (1 << i)) 
					ans[i] += dp[mask];
		}

	}
	for(int i = 0; i < n; i++)
		cout << fixed << setprecision(8) << ans[i] << " ";
}#include<bits/stdc++.h>
#define MAX 2097152
#define MAXN 21
#define ld double
using namespace std;

ld dp[MAX];
ld p[MAXN];
ld sum[MAX];
ld ans[MAXN];
int main(){
	int n, k;
	cin >> n >> k;
	int cont = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i] > 0.00000001) cont++;
	}
	k = min(k, cont);

	dp[0] = 1.;
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i))
				sum[mask] += p[i];
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)){
				int maski = mask - (1 << i);
				if(sum[maski] < 0.99999999)
					dp[mask] += dp[maski] / (1. - sum[maski]) * p[i];
			}
		}
	}
	
	for(int mask = 1; mask < (1 << n); mask++){
		cont = 0;
		for(int i = 0; i <= 20; i++){
			if(mask & (1 << i)) cont++;
		}
		if(cont == k){
			for(int i = 0; i <= 20; i++)
				if(mask & (1 << i)) 
					ans[i] += dp[mask];
		}

	}
	for(int i = 0; i < n; i++)
		cout << fixed << setprecision(8) << ans[i] << " ";
}