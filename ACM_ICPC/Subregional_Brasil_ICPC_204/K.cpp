#include<bits/stdc++.h>
using namespace std;
int main(){
	int c, n;
	scanf("%d %d", &c, &n);
	c*= 2;
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i] *= 2;
	}

	for(int l = 1; l < c/n; l++){
		int p = a[0] + l;
		int flag = 1;
		for(int i = 1; i < n; i++, p+= c/n){
			int p1 = (p + c/n);
			if(a[i] <= p || a[i] >= p1)
				flag = 0;
		}
		if(flag) {
			printf("S\n");
			return 0;
		}
	}
	printf("N\n");
}