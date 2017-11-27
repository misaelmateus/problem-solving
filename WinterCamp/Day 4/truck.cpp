#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define ld long double
#define MAXN 111
using namespace std;

ld ans;
int gr[MAXN][MAXN];
int n, z;
int dist[MAXN];
vector<ii> ar;
void bellman_ford( int a ){
	for(int i = 0; i < MAXN; i++) dist[i] = -(1 << 30);

	dist[a] = 0;

	for(int k = 1; k <= n; k++){
		int dist1[MAXN];
		for(int i = 0; i < MAXN; i++) dist1[i] = max(dist[i], -(1 << 30));
		for(int i = 0; i < ar.size(); i++){
			int u = ar[i].first, v = ar[i].second;
			dist1[v] = max(dist1[v], dist[u] + gr[u][v]);
		}
		for(int i = 1; i<= n; i++) dist[i] = dist1[i];

		for(int i = 1; i <= n; i++){
			ans = max(ans, (ld)dist[a] / k);
		}
	}
}
int main(){
	
	cin >> n >> z;
	for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				gr[i][j] = -1;
			}
	while(z--){
		int a, b, c;
		cin >> a >> b >> c;
		if(gr[a][b] < c)
			gr[a][b] = c;
	}
	for(int j = 1; j <= n; j++)
		for(int i = 1; i <= n; i++)
			if(gr[i][j] != -1) ar.push_back({i, j});

	for(int i = 1; i <= n; i++) bellman_ford(i);

	

	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}
