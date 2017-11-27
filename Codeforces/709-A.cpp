//   Author : Misael Mateus 
//   Submission date: 2016-08-24 22:04:31
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, b, d;
	scanf("%d %d %d", &n, &b, &d);
	int cont = 0;
	int atual = 0;
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		if(aux <= b){
			atual += aux;
			if(atual > d)
				cont++, atual = 0;
		}
	}
	printf("%d\n", cont);
	
	return 0;
}
