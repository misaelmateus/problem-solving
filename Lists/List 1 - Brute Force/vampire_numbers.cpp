#include<bits/stdc++.h>
#define ll long long
using namespace std;

int v[10];
int v1[10];
int v2[10];
int n;
ll num;

bool test(int p){

	for(int i = 1; i < p; i++){
		if(v1[i] + v1[i-1] == 0 || v2[i] + v2[i-1] == 0)
			return false;
	}
	ll num1 = 0, num2 = 0;
	ll mult = 1LL;
	for(int i = n-1; i >= p; i--){
		num1 += mult*9;
		num2 += mult*9;
		mult *= 10;
	}
	for(int i = p-1; i >= 0; i--){
		num1 += mult*v1[i];
		num2 += mult*v2[i];
		mult *= 10;
	}
	if(num1 * num2 < num) return false;
	mult = 1LL;
	for(int i = n-1; i >= p; i--){
		num1 -= mult*9;
		num2 -= mult*9;
		mult *= 10;
	}
	if(num1 * num2 > num)
		return false;

	return true;
}
ll f(int i){
	if(i == n){
		return true;
	}
	for(int j = 0; j < 10; j++){
		for(int l = 0; l < 10; l++){
			if(!i & (!j || !l)) continue;
			v[l]--;
			v[j]--;
			v1[i] = j;
			v2[i] = l;
			if(v[l] >= 0 && v[j] >= 0){
				if(test(i+1)){
					int ans = f(i+1);
					if(ans)
						return true;
				}
			}
			v[l]++;
			v[j]++;
		}
	}


	return false;
}
ll solve(ll N){
	num = N;
	n = 0;
	memset(v, 0, sizeof(v));
	memset(v1, 0, sizeof(v1));
	memset(v2, 0, sizeof(v2));
	while(N > 0){
		n++;
		v[N%10]++;
		N /= 10;
	}

	
	if(n%2 == 1 || ((n /= 2) && !f(0) )){
		printf("%lld: no\n", num);
	}
	else
		printf("%lld: yes\n", num);

}

int main(){
	ll N;
	while(scanf("%lld", &N) && N){
		solve(N);
	}

	return 0;
}