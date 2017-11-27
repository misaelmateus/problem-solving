#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	queue<int> q[n];
	int ans = 0;
	for(int i = 0; i  < n; i++){
		int t, num;
		scanf("%d", &t);
		while(t--){
			scanf("%d", &num);
			q[i].push(num);
		}
	}

	int i = 0, empty = 0;
	while(k != 0 && empty != n){
		if(q[i].empty()){
			empty++;
			if(50 >= ans)
				ans += 50, k--;
			i = (i+1) % n;
			continue;
		}
		empty = 0;
		int u = q[i].front();
		q[i].pop();
		if(u >= ans)
			ans += u, k--;
		i = (i+1) % n;
	}

	ans += k * 50;

	printf("%d\n", ans);
}