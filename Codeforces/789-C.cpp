//   Author : Misael Mateus 
//   Submission date: 2017-03-29 22:01:15
#include<bits/stdc++.h>
#define ll long long
#define MAXN 100100
using namespace std;
ll b[MAXN];
ll a[MAXN];

ll ABS(ll a){
	if(a >= 0)
		return a;
	return -a;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n-1; i++)
		b[i] = ABS(a[i] - a[i+1]);

	int flag = 0;
	ll best = 0;
	ll ans = 0;
	for(int i = n-2; i >= 0; i--){
		if(flag == 0)
			ans -= b[i];
		else{
			ans += b[i];
			best = max(best, ans);
		}
		flag = 1 - flag;
		if(ans < 0)
			ans = 0;
	}		

	ans = 0;
	flag = 1;
	for(int i = n-2; i >= 0; i--){
		if(flag == 0)
			ans -= b[i];
		else{
			ans += b[i];
			best = max(best, ans);
		}
		flag = 1 - flag;
		if(ans < 0)
			ans = 0;
	}

	cout << best << "\n";
}