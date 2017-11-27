#include<bits/stdc++.h>
#define MAXM 501
using namespace std;

map<vector<int>, int > mapa;

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	int A[M], B[M], C[M], D[M];
	for(int i = 0; i < M; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	int ans = 0;
	for(int j = 0; j < N; j++){
		vector<int> b(MAXM);
		int X, Y, Z;
		scanf("%d %d %d", &X, &Y, &Z);
		for(int i = 0; i < M; i++){
			int v = A[i]*X + B[i]*Y + C[i]*Z;
			b[i] = (v >= D[i]);
		}
		mapa[b]++;
		ans = max(ans, mapa[b]);
	}
	printf("%d\n", ans);

}