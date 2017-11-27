#include<bits/stdc++.h>
using namespace std;

int mask[100000];

int build(int A){
	int x = A;
	for(int i = 0; i < 5; i++, x /= 10){
		mask[A] |= 1 << ( x % 10);
	}
}
int verify(int A, int B){
	int mark = mask[A] | mask[B];
	if(mark != (1 << 10) - 1)
		return false;
	return true;
}
void solve(int N){
	int cont = 0;
	for(int b = 1; b < 100000; b++){
		int a = b*N;
		if(a >= 100000 || !verify(a, b))
			continue;
		printf("%05d / %05d = %d\n", a, b, N);
		cont++;
	}
	if(cont == 0)
		printf("There are no solutions for %d.\n", N);
}
int main(){
	for(int i = 0; i < 100000; i++) build(i);

	int N;
	int flag = 0;
	while(scanf("%d", &N) && N){
		if(flag ) cout << "\n";
		flag = 1;
		solve(N);
	}
}