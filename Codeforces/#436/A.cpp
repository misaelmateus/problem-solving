#include<bits/stdc++.h>
using namespace std;

map<int, int> cont;
int main(){
	int n, num;
	scanf("%d", &n);
	int a1 = -1, a2 = -1;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		cont[num]++;
		if(a1 == -1 )
			a1 = num;
		else if(a2 == -1 && num != a1)
			a2 = num;
	}
	if(a1 != -1 && a2 != -1 && cont[a1] + cont[a2] == n){
		printf("YES\n%d %d\n", a1, a2);
	}
	else printf("NO\n");
}