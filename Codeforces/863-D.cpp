//   Author : Misael Mateus 
//   Submission date: 2017-09-22 20:28:27
#include<bits/stdc++.h>
#define MAXN 200010
#define ii pair<int, int>
using namespace std;
int v[MAXN];
pair<int, ii> Q[MAXN];
int main(){
	int n, q, m;
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= q; i++)
		scanf("%d %d %d", &Q[i].first, &Q[i].second.first, &Q[i].second.second);

	for(int l = 1; l <= m; l++){
		int p;
		scanf("%d", &p);
		for(int i = q; i > 0; i--){
			if(p < Q[i].second.first || p > Q[i].second.second) continue;
			if(Q[i].first == 1){
				if(p != Q[i].second.first)
					p--;
				else p = Q[i].second.second;
			}
			else
				p = Q[i].second.second - p + Q[i].second.first;
		}

		printf("%d ", v[p]);
	}
	printf("\n");
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ii pair<int, int>
using namespace std;
int v[MAXN];
pair<int, ii> Q[MAXN];
int main(){
	int n, q, m;
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= q; i++)
		scanf("%d %d %d", &Q[i].first, &Q[i].second.first, &Q[i].second.second);

	for(int l = 1; l <= m; l++){
		int p;
		scanf("%d", &p);
		for(int i = q; i > 0; i--){
			if(p < Q[i].second.first || p > Q[i].second.second) continue;
			if(Q[i].first == 1){
				if(p != Q[i].second.first)
					p--;
				else p = Q[i].second.second;
			}
			else
				p = Q[i].second.second - p + Q[i].second.first;
		}

		printf("%d ", v[p]);
	}
	printf("\n");
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ii pair<int, int>
using namespace std;
int v[MAXN];
pair<int, ii> Q[MAXN];
int main(){
	int n, q, m;
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= q; i++)
		scanf("%d %d %d", &Q[i].first, &Q[i].second.first, &Q[i].second.second);

	for(int l = 1; l <= m; l++){
		int p;
		scanf("%d", &p);
		for(int i = q; i > 0; i--){
			if(p < Q[i].second.first || p > Q[i].second.second) continue;
			if(Q[i].first == 1){
				if(p != Q[i].second.first)
					p--;
				else p = Q[i].second.second;
			}
			else
				p = Q[i].second.second - p + Q[i].second.first;
		}

		printf("%d ", v[p]);
	}
	printf("\n");
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ii pair<int, int>
using namespace std;
int v[MAXN];
pair<int, ii> Q[MAXN];
int main(){
	int n, q, m;
	scanf("%d %d %d", &n, &q, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= q; i++)
		scanf("%d %d %d", &Q[i].first, &Q[i].second.first, &Q[i].second.second);

	for(int l = 1; l <= m; l++){
		int p;
		scanf("%d", &p);
		for(int i = q; i > 0; i--){
			if(p < Q[i].second.first || p > Q[i].second.second) continue;
			if(Q[i].first == 1){
				if(p != Q[i].second.first)
					p--;
				else p = Q[i].second.second;
			}
			else
				p = Q[i].second.second - p + Q[i].second.first;
		}

		printf("%d ", v[p]);
	}
	printf("\n");
	return 0;
}