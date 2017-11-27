//   Author : Misael Mateus 
//   Submission date: 2016-06-17 23:27:24
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int v[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);

	sort(v, v+n);
	int prox = 1;
	for(int i = 0; i < n; i++){
		if(v[i] >= prox){
			v[i] = prox;
			prox++;
		}
		else{
			continue;
		}
	}
	cout << prox << endl;
}