#include<bits/stdc++.h>
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++)
#define rep(a, b) fr(a, 0, b)
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		int N, C, V;
		scanf("%d %d %d", &N, &C, &V);
		int nota[N];
		rep(i, N) scanf("%d", &nota[i]);

		sort(nota, nota+N );

		int i;
		for(i = N-1; i >= 0; i--){
			if(nota[i] < C)
				break;
		}

		printf("Caso %d: %d %d\n", k, N-1 - i, nota[N-V]);
	}

}