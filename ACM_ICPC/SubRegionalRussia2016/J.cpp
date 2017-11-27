#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("java2016.in", "r", stdin);
	freopen("java2016.out", "w", stdout);
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("? / ? / ?\n");
		return 0;
	}
	printf("a = ? max ?\n");
	for(char c = 'b'; c <= 'r'; c++)
		printf("%c = %c max %c\n", c, (char)(c-1), (char)(c-1));
	printf("s = r / r\n");
	for(char c = 't'; c <= 'z'; c++)
		printf("%c = %c + %c\n", c, (char)(c-1), (char)(c-1));
	int mult = 128;
	int flag = 0;
	for(char c = 'z'; c >= 's'; c--, mult /= 2){
		if(n >= mult){
			n -= mult;
			if(flag) printf(" + ");
			flag = 1;
			printf("%c", c);
		}
	}
	printf("\n");
}