#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		char cor_atual = '-';
		int lim = -1;
		int ans = 0;

		for(int i = 0; i <= n-k; i++){
			if(s[i] != cor_atual || i >= lim)
				cor_atual = s[i], lim = i+k, ans++;
		}
		if(lim < n)
			ans++;
		for(int i = n-k+1; i < n; i++)
			if(s[i] != s[n-k]) ans = (1 << 30);

		cor_atual = '-';
		lim = n;
		int ans1 = 0;

		for(int i = n-1; i >= k-1; i--){
			if(s[i] != cor_atual || i <= lim)
				cor_atual = s[i], lim = i-k, ans1++;
		}
		if(lim > -1)
			ans1++;
		for(int i = k-2; i >= 0; i--)
			if(s[i] != s[k-1]) ans1 = (1 << 30);
		ans = min(ans, ans1);
		if(ans == (1 << 30)) ans = -1;
		cout << ans << "\n";
	}

	return 0;
}