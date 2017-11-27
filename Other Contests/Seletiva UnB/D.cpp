#include<bits/stdc++.h>
#define MAXN 100010
#define L 1000000007LL
using namespace std;
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>

int prime[MAXN];
int cont[MAXN];
int main(){
	for(int i = 2; i < MAXN; i++){
		if(!prime[i])
			for(int j = i; j < MAXN; j+= i)
				prime[j] = i;
	}

	int T, num;
	scanf("%d", &T);
	vector< ii > query;
	vector<int> ans(T+1);
	rep(i, T) {
		scanf("%d", &num);
		query.push_back(make_pair(num, i+1));
	}
	sort(query.begin(), query.end());
	int ult = 2;
	rep(i, T){
		fr(j, ult, query[i].first+1){
			int j1 = j;
			while(j1 > 1){
				cont[prime[j1]]++;
				j1 /= prime[j1];
			}
		}
		int res = 1;
		rep(j, query[i].first+1)
			res = (int)( ((long long)res * (cont[j]/2 + 1))%L );
		ans[query[i].second] = res;
		ult = query[i].first+1;
	}
	fr(i, 1, T+1)
		printf("Caso %d: %d\n", i, ans[i]);

	return 0;	
}