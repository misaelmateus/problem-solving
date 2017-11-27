//   Author : Misael Mateus 
//   Submission date: 2017-09-05 15:07:08
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1000010
using namespace std;




int crivo[MAXN];
int cont[MAXN];
int main(){
	for(int i = 2; i < MAXN; i++){
		if(!crivo[i]){
			for(int j = i; j < MAXN; j+= i)
				crivo[j] = i;
		}
	}

	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	ll ans = (ll)n * min(x, y);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cont[a[i]]++;
	}

	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		ans = min(ans, (ll)x * tot);
	}


	sort(a, a+n);
	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		ll count = 0;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		for(int j = i-1; j < MAXN; j+= i){
			tot -= cont[j];
		}
		if(tot > n/2) continue;
		int j;
		int b = 0;
		for(j = 0; j < n && count < ans; j++){
			while(b < a[j]) b += i;
			count += min((ll) x, (ll)y * (b - a[j]));
		}
		if(j == n) ans = min(ans, count);
	}

	printf("%lld\n", ans);
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1000010
using namespace std;




int crivo[MAXN];
int cont[MAXN];
int main(){
	for(int i = 2; i < MAXN; i++){
		if(!crivo[i]){
			for(int j = i; j < MAXN; j+= i)
				crivo[j] = i;
		}
	}

	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	ll ans = (ll)n * min(x, y);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cont[a[i]]++;
	}

	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		ans = min(ans, (ll)x * tot);
	}


	sort(a, a+n);
	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		ll count = 0;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		for(int j = i-1; j < MAXN; j+= i){
			tot -= cont[j];
		}
		if(tot > n/2) continue;
		int j;
		int b = 0;
		for(j = 0; j < n && count < ans; j++){
			while(b < a[j]) b += i;
			count += min((ll) x, (ll)y * (b - a[j]));
		}
		if(j == n) ans = min(ans, count);
	}

	printf("%lld\n", ans);
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1000010
using namespace std;




int crivo[MAXN];
int cont[MAXN];
int main(){
	for(int i = 2; i < MAXN; i++){
		if(!crivo[i]){
			for(int j = i; j < MAXN; j+= i)
				crivo[j] = i;
		}
	}

	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	ll ans = (ll)n * min(x, y);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cont[a[i]]++;
	}

	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		ans = min(ans, (ll)x * tot);
	}


	sort(a, a+n);
	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		ll count = 0;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		for(int j = i-1; j < MAXN; j+= i){
			tot -= cont[j];
		}
		if(tot > n/2) continue;
		int j;
		int b = 0;
		for(j = 0; j < n && count < ans; j++){
			while(b < a[j]) b += i;
			count += min((ll) x, (ll)y * (b - a[j]));
		}
		if(j == n) ans = min(ans, count);
	}

	printf("%lld\n", ans);
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1000010
using namespace std;




int crivo[MAXN];
int cont[MAXN];
int main(){
	for(int i = 2; i < MAXN; i++){
		if(!crivo[i]){
			for(int j = i; j < MAXN; j+= i)
				crivo[j] = i;
		}
	}

	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	ll ans = (ll)n * min(x, y);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cont[a[i]]++;
	}

	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		ans = min(ans, (ll)x * tot);
	}


	sort(a, a+n);
	for(int i = 2; i < MAXN; i++){
		if(crivo[i] != i) continue;
		ll count = 0;
		int tot = n;
		for(int j = i; j < MAXN; j+= i){
			tot -= cont[j];
		}
		for(int j = i-1; j < MAXN; j+= i){
			tot -= cont[j];
		}
		if(tot > n/2) continue;
		int j;
		int b = 0;
		for(j = 0; j < n && count < ans; j++){
			while(b < a[j]) b += i;
			count += min((ll) x, (ll)y * (b - a[j]));
		}
		if(j == n) ans = min(ans, count);
	}

	printf("%lld\n", ans);
}