#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
int cont[MAXN];
int v[MAXN];
int mark[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		cont[v[i]]++;
	}
	int j = 1;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(cont[v[i]] > 1){
			while(cont[j]) j++;
			if(j > v[i] && !mark[v[i]]){
				mark[v[i]] = 1;
				continue;
			}
			cont[v[i]]--;
			cont[j]++;
			v[i] = j;
			ans++;
		}
	}

	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");


}