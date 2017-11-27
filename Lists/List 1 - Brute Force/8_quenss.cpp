#include<bits/stdc++.h>
using namespace std;

int A[20][20];
vector<int> v(20);
int col[60], row[60], d1[60], d2[60];
int cont;
int N;
void f(int i){
	if(i == N){
		cont++;
		return;
	}
	
	for(int j = 0; j < N; j++){
		if(A[i][j] == 1) continue;
		if(!row[i] && !col[j] && !d1[i+j] && !d2[(i - j) + 20])
		{
			v[i] = j;
			row[i] = 1;
			col[j] = 1;
			d1[(i+j)] = 1;
			d2[(i - j) + 20] = 1;
			f(i+1);

			row[i] = 0;
			col[j] = 0;
			d1[(i+j)] = 0;
			d2[(i - j) + 20] = 0;
		}
	}

}
int main(){
	int T, k =0;
	
	while(scanf("%d", &N) && N){
		k++;
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		memset(A, 0, sizeof(A));
		char s[20][20];
		cont = 0;
		for(int i = 0; i < N; i++){
			scanf(" %s", s[i]);
			for(int j = 0; j < N; j++){
				if(s[i][j] == '*')
					A[i][j] = 1;
			}
		}
		f(0);

		printf("Case %d: %d\n", k, cont);
	}
}