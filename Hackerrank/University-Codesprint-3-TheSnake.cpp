#include<bits/stdc++.h>
using namespace std;

int v[70][70];
int n;
int k = 1;
char c;

int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
int f(int i, int j){
	v[i][j] = k++;
	vector<int> order;
	if(c == 'e')
		order = {2, 0, 1, 3};
	else if(c == 'w')
		order = {3, 0, 1, 2};
	else if(c == 's')
		order = {0, 2, 3, 1};
	else order = {1, 2, 3, 0};

	for(int l = 0; l < 4; l++){
		int i1 = i + x[l], j1 = j + y[l];
		if(i1 < 0 || j1 < 0 || i1 >= n || j1 >= n || v[i1][j1]) continue;
		f(i1, j1);
		return 0;
	}
}
int main(){
	int n, a, b;
	cin >> n >> c >> a >> b;
	f(a, b);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
}