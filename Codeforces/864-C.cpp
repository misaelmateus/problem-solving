//   Author : Misael Mateus 
//   Submission date: 2017-09-25 15:50:23
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, f, k;
	scanf("%d %d %d %d", &a, &b, &f, &k);
	int p = 0;
	int gas = b;
	int cont = 0;
	int ans = 0;
	for(int i = 0; i < k; i++){
		if(gas >= a){
			p = a - p;
			gas -= a;
			continue;
		}
		if((!p && gas < f && (!i || b - f < f)) || (p && gas < (a - f) && (!i || b - (a-f) < (a - f))))
		{
			printf("-1\n");
			return 0;
		}
		if(!p && gas < f)
			ans++, gas = b - f;
		else if(p && gas < (a - f)) 
			ans++, gas = b - (a - f);
		if(gas < 0){
			printf("-1\n");
			return 0;
		}
		if(gas >= a){
			p = a - p;
			gas -= a;
			continue;
		}
		else{
			if(!p)
				ans++, gas = b - (a - f);
			else ans++, gas = b - f;
		}
		if(gas < 0){
			printf("-1\n");
			return 0;
		}
		p = a - p;
	}
	printf("%d\n", ans);

}