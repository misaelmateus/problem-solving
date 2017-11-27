#include<bits/stdc++.h>
#define ld long double
using namespace std;
int main(){

	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		unordered_map<int, int> m;
		vector<pair<int, int> > v(n);
		for(int i = 0;  i < n; i++){
			scanf("%d %d", &v[i].first, &v[i].second);
			m[v[i].first]++;	
		}
		long long cont = 0;
		for(int i = 0; i < n; i++){
			cont += m[v[i].second];
		}
		printf("%lld\n", cont);
	}
}