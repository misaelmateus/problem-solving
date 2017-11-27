//   Author : Misael Mateus 
//   Submission date: 2017-09-06 18:36:55
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n, k;
	ll custo = 0LL;
	scanf("%d %d", &n, &k);
	int ans[n+1];
	priority_queue< pair<int, int > > pq;
	for(int i = 1; i <= n+k; i++){
		if(i <= n){
			int aux;
			scanf("%d", &aux);
			pq.push({aux, i});
		}
		if(i > k){
			ans[pq.top().second] = i;
			custo += (ll)pq.top().first * (i - pq.top().second);
			pq.pop();
		}
	}
	printf("%lld\n", custo);
	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}