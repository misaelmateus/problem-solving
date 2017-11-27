#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;
int cont[MAXN];
char c[MAXN];
int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		unordered_map<ll, int> mapa;
		memset(cont, 0, sizeof(cont));
		
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i = 0; i < n; i++){
			scanf(" %s", c);
			ll hash = 31;
			int t = strlen(c);
			for(int j = t-1; j >= 0; j--){
				hash = hash * 31LL + c[j];
				mapa[hash]++;
				if(mapa[hash] > cont[t-j])
					cont[t-j] = mapa[hash];
			}
		}

		while(q--){
			int x;
			scanf("%d", &x);
			printf("%d\n", cont[x]);
		}
	}
}