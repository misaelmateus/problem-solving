//   Author : Misael Mateus 
//   Submission date: 2017-04-23 22:29:46
#include<bits/stdc++.h>
#define ll long long
#define fr(a, b, c) for(int a = (b); (a) < (c); a++)
#define rep(a, b) fr(a, 0 , b)
#define RI(a) scanf("%d", &a)
using namespace std;

int main(){
	int N, K;
	RI(N);
	RI(K);
	int v[N];
	int rep = -1;
	rep(i, N){
		RI(v[i]);
		if(rep != -1 && v[i] % K != rep) {
			printf("-1\n");
			return 0;
		}
		rep = v[i] % K;
	}

	sort(v, v+N);
	ll resp = 0LL;
	for(int i = 1; i < N; i++){
		resp += (ll)(v[i] - v[0]) / (ll)(K);
		
	}

	printf("%lld\n", resp);


	return 0;
}#include<bits/stdc++.h>
#define ll long long
#define fr(a, b, c) for(int a = (b); (a) < (c); a++)
#define rep(a, b) fr(a, 0 , b)
#define RI(a) scanf("%d", &a)
using namespace std;

int main(){
	int N, K;
	RI(N);
	RI(K);
	int v[N];
	int rep = -1;
	rep(i, N){
		RI(v[i]);
		if(rep != -1 && v[i] % K != rep) {
			printf("-1\n");
			return 0;
		}
		rep = v[i] % K;
	}

	sort(v, v+N);
	ll resp = 0LL;
	for(int i = 1; i < N; i++){
		resp += (ll)(v[i] - v[0]) / (ll)(K);
		
	}

	printf("%lld\n", resp);


	return 0;
}#include<bits/stdc++.h>
#define ll long long
#define fr(a, b, c) for(int a = (b); (a) < (c); a++)
#define rep(a, b) fr(a, 0 , b)
#define RI(a) scanf("%d", &a)
using namespace std;

int main(){
	int N, K;
	RI(N);
	RI(K);
	int v[N];
	int rep = -1;
	rep(i, N){
		RI(v[i]);
		if(rep != -1 && v[i] % K != rep) {
			printf("-1\n");
			return 0;
		}
		rep = v[i] % K;
	}

	sort(v, v+N);
	ll resp = 0LL;
	for(int i = 1; i < N; i++){
		resp += (ll)(v[i] - v[0]) / (ll)(K);
		
	}

	printf("%lld\n", resp);


	return 0;
}#include<bits/stdc++.h>
#define ll long long
#define fr(a, b, c) for(int a = (b); (a) < (c); a++)
#define rep(a, b) fr(a, 0 , b)
#define RI(a) scanf("%d", &a)
using namespace std;

int main(){
	int N, K;
	RI(N);
	RI(K);
	int v[N];
	int rep = -1;
	rep(i, N){
		RI(v[i]);
		if(rep != -1 && v[i] % K != rep) {
			printf("-1\n");
			return 0;
		}
		rep = v[i] % K;
	}

	sort(v, v+N);
	ll resp = 0LL;
	for(int i = 1; i < N; i++){
		resp += (ll)(v[i] - v[0]) / (ll)(K);
		
	}

	printf("%lld\n", resp);


	return 0;
}