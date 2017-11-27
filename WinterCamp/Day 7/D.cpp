#include<bits/stdc++.h>
using namespace std;
int m[3][3];
int m1[3][3];
int ans = (1 << 30);

void f(int i, int j){
	if(i == 1 && j == 2){
		int sum = m1[0][0] + m1[0][1] + m1[0][2];
		m1[1][2] = sum - m1[1][0] - m1[1][1];
		for(int l = 0; l < 3; l++)
			m1[2][l] = sum - m1[0][l] - m1[1][l];

		if(m1[2][0] + m1[2][1] + m1[2][2] != sum || m1[0][0] + m1[1][1] + m1[2][2] != sum || 
			m1[0][2] + m1[1][1] + m1[2][0] != sum)
			return;
		vector<int> mark(10, 0);
		for(int l = 0; l < 3; l++)
			for(int p = 0; p < 3; p++){
				if(m1[l][p] > 9 || m1[l][p] < 1 || mark[m1[l][p]])
					return ;
				mark[m1[l][p]] = 1;
			}
		int custo = 0;
		for(int l = 0; l < 3; l++)
			for(int p = 0; p < 3; p++)
				custo += abs(m[l][p] - m1[l][p]);
		ans = min(ans, custo);
		return;
	}
	for(int l = 1; l <= 9; l++){
		m1[i][j] = l;
		if(j == 2)
			f(i+1, 0);
		else f(i, j+1);
	}
}
int main(){
	for(int l = 0; l < 3; l++)
		for(int p = 0; p < 3; p++)
			cin >> m[l][p];
	f(0, 0);
	cout << ans << "\n";
}