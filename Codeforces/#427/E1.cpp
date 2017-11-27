#include<bits/stdc++.h>
using namespace std;
int v[5001];
int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int aux;
		scanf("%d", &aux);
		v[aux]++;
	}
	int ans = 0, t = 0;
	for(int i = 0; i <= 4000; i++){
		int ans1 = 0;
		for(int j = 0; j <= i; j++){
			if(j > i - j)
				break;
			if(j == i - j){
				ans1 += v[j]/2;
			}
			else ans1 += min(v[j], v[i-j]);
		}
		if(ans1 > ans) ans = ans1, t = 1;
		else if(ans1 == ans) t++;
	}

	printf("%d %d\n", ans, t);

	return 0;

}