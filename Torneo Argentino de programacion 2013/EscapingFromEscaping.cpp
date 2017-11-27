#include<bits/stdc++.h>
using namespace std;
bool has[1 << 16][16];
int cont[17];
char s[100010];
int main(){
	scanf("%s", s);
	int aux;
	int t = strlen(s);
	for(int i = 0; i < t; i++){
		aux = 0;
		for(int j = 0, m = min(16, (t-i)); j < m; j++){
			aux = (aux << 1) + (int)(s[j+i] - '0');
			if(!has[aux][j]) cont[j]++, has[aux][j] = 1;
		}
	}
	for(int i = 1; i <= 17; i++){
		if(cont[i-1] < (1 << i)){
			printf("%d\n", i);
			break;
		}
	}
	
}