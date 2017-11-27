//   Author : Misael Mateus 
//   Submission date: 2017-09-08 12:33:51
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n, k, M;
	scanf("%d %d %d", &n, &k, &M);
	int t[k];
	int T = 0;
	for(int i = 0; i < k; i++){
		scanf("%d", &t[i]);
		T += t[i];
	}
	sort(t, t+k);
	int ans = 0;
	for(int i = 0; i <= n; i++){
		int temp = i*(k+1);
		int t_now = M - i*T;
		if(t_now < 0) break;
		for(int j = 0; j < k; j++){
			int x = min((n-i), t_now/t[j]);
			t_now -= x*t[j];
			temp += x;

		}

		ans = max(ans, temp);
	}

	printf("%d\n", ans);
}