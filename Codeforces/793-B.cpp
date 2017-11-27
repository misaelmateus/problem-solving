//   Author : Misael Mateus 
//   Submission date: 2017-04-23 22:34:34
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); (a) < (c); a++)
#define rep(a, b) fr(a, 0 , b)
#define RI(a) scanf("%d", &a)
#define MAXN 1010
#define INF 1000000
using namespace std;

int x_c[] = {1, -1, 0, 0};
int y_c[] = {0, 0, 1, -1};
int M[MAXN][MAXN][4];
char s[MAXN][MAXN];
int main(){
	int n, m;
	rep(i, MAXN)
		rep(j, MAXN)
			rep(l, 4) M[i][j][l] = INF;
	RI(n); RI(m);
	int xi, yi, xf, yf;
	rep(i, n){
		scanf(" %s", s[i]);
		rep(j, m){
			if(s[i][j] == 'S')
				xi = i, yi = j;
			else if(s[i][j] == 'T')
				xf = i, yf = j;
		}
	}
	priority_queue< pair<ii, ii> > q;
	rep(i, 4) M[xi][yi][i] = 0, q.push({{0, i}, {xi, yi}});
	while(!q.empty()){
		int x = q.top().second.first;
		int y = q.top().second.second;
		int p = q.top().first.second;
		int d = -q.top().first.first;

		
		q.pop();
		if(M[x][y][p] != d)
			continue;
		rep(i, 4){
			int x1 = x + x_c[i], y1 = y + y_c[i];
			if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || s[x1][y1] == '*')
				continue;
			int d1 = M[x][y][p] + (int)(p != i);
			if(d1 > 2 || M[x1][y1][i] <= d1)
				continue;
			M[x1][y1][i] = d1;
			q.push({{-d1, i}, {x1, y1}});
		}
	}

	int resp = INF;
	rep(i, 4) resp = min(resp, M[xf][yf][i]);

	if(resp == INF)
		printf("NO\n");
	else printf("YES\n"); 

	return 0;
}
