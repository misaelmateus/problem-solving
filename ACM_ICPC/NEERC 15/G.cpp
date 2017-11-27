#include<bits/stdc++.h>
using namespace std;
int mark[10001][1001];
int ma[10001];
int ma_j[10001];
int se[10001];
int se_j[10001];
vector<pair<int, int> > num[10001];
int main(){
	freopen("generators.in", "r", stdin);
    freopen("generators.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = 0;
	int dif = -(1e9);
	int dif_i;
	for(int i = 0; i < n; i++){
		int a, b, x, c;
		scanf("%d %d %d %d", &x, &a, &b, &c);
		int j = 0;
		while(!mark[i][x]){
			mark[i][x] = 1;
			num[i].push_back({x, j});
			x = (a*x + b) % c;
			j++;
		}
		pair<int, int> p = *max_element(num[i].begin(), num[i].end());
		ma[i] = p.first;
		ma_j[i] = p.second;
		sum += ma[i];
		se[i] = -1;
		for(int j = 0; j < num[i].size(); j++)
			if(num[i][j].first != ma[i]  && dif < num[i][j].first - ma[i] && (ma[i] - num[i][j].first) % k != 0)
				se[i] = num[i][j].first, se_j[i] = num[i][j].second, dif = se[i] - ma[i], dif_i = i;

			
	}
	if(sum % k != 0){
		printf("%d\n", sum);
		for(int i = 0; i < n; i++){
			if(i) printf(" ");
			printf("%d", ma_j[i]);
		}
		printf("\n");
		return 0;
	}
	if(dif == -(1e9)){
		printf("-1\n");
		return 0;
	}
	sum += dif;
	printf("%d\n", sum);
	for(int i = 0; i < n; i++){
		if(i) printf(" ");
		if(dif_i == i) printf("%d", se_j[i]);
		else printf("%d", ma_j[i]);
	}
	printf("\n");
	return 0;

}