#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
vector<ii> positions;
int A[10][10];
int n;
int row[10];
int column[10];
int block[10];

bool f(int p){
	if(p == positions.size())
	{
		for(int i = 0; i < n*n; i++){
			for(int j = 0; j < n*n; j++){
				if(j) printf(" ");
				printf("%d", A[i][j]);
			}
			printf("\n");
		}
		return true;
	}

	int x = positions[p].first, y = positions[p].second;

	int mask = row[x] | column[y] | block[(x/n)*n + y/n];
	for(int i = 1; i <= n*n; i++){
		if(!(mask & (1 << i))){
			row[x] |= (1 << i);
			column[y] |= (1 << i);
			block[(x/n)*n + y/n] |= (1 << i);
			A[x][y] = i;
			bool ans = f(p+1);
			if(ans) return true;
			A[x][y] = 0;
			row[x] ^= (1 << i);
			column[y] ^= (1 << i);
			block[(x/n)*n + y/n] ^= (1 << i);			
		}
	}
	return false;
}
int main(){
	int k =0;
	while(scanf("%d", &n) != EOF){
		if(k) printf("\n");
		k++;
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(block, 0, sizeof(block));
		positions.clear();
		bool go = true;
		for(int i = 0; i < n*n && go; i++){
			for(int j = 0; j < n*n; j++){
				scanf("%d", &A[i][j]);
				if(A[i][j]){
					int x = (1 << A[i][j]);
					if((row[i] & x) || (column[j] & x) || (block[(i/n)*n + (j/n)] & x)){
						cout << i << j << endl;
						go = false;
						break;
					}
					row[i] |= x;
					column[j] |= x;
					block[(i/n)*n + (j/n)] |= x;
				}
				else positions.push_back({i, j});
			}
		}
		if(go) go = f(0);
		if(!go)
			printf("NO SOLUTION\n");
	}

}