//   Author : Misael Mateus 
//   Submission date: 2017-08-29 20:29:52
#include<bits/stdc++.h>
using namespace std;
int main(){
	int r, d, n;
	scanf("%d %d %d", &r, &d, &n);
	int cont = 0;
	while(n--){
		int xi, yi, ri;
		scanf("%d %d %d", &xi, &yi, &ri);
		if(xi*xi + yi*yi >= (ri + r - d) * (ri + r - d) && xi*xi + yi*yi <= (r - ri) * (r - ri))
			cont++;
	}

	printf("%d\n", cont);
}