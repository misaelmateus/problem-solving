#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int cont = 0;
	for(int i = 0; i < n; i++){
		int flag = 1;
		for(int j = 0 ; j < m; j++){
			int aux;
			cin >> aux;
			if(!aux) flag = 0;
		}
		cont += flag;
	}
	printf("%d\n", cont);
}