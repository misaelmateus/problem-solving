//   Author : Misael Mateus 
//   Submission date: 2017-03-29 21:55:30
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;

	int a;
	while(n--){
		scanf("%d", &a);
		ans += (a/k) + (int)(a%k != 0);
	}

	int resp = ans/2 + (int)(ans%2 != 0);

	printf("%d\n", resp);


	return 0;
}