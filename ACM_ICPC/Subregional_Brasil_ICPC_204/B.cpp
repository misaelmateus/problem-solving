#include<bits/stdc++.h>
using namespace std;
int main(){
	int P;
	scanf("%d", &P);
	int i = 1;
	int cont = 0;
	do{
		if(i > P/2)
			i = (i - P/2)*2 - 1;
		else i *= 2;
		cont++;
	}while(i != 1);
	printf("%d\n", cont);
}