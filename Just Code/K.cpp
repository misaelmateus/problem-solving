#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		double m;
		int num;
		scanf("%d %lf", &n, &m);
		num = (int)(ceil(n * m) + 0.01);
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			if(x >= 50)
				num--;
		}
		if(num <= 0)
			printf("YES\n");
		else printf("NO\n");
	}
}