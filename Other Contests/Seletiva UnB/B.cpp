#include<bits/stdc++.h>
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++)
#define rep(a, b) fr(a, 0, b)
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		int N, K;
		scanf("%d %d", &N, &K);

		printf("Caso %d: %d\n",k, (int)(N/(K-1) + (int)(N % (K-1) != 0)));

	}
}