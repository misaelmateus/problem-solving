#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
vector<int> gr[MAXN];
vector<pair<int, int> > gr1[MAXN];

vector<vector<int> > backtracking(vector<int> scc){
	int n = scc.size();
	int dist[n][n][1 << n];
	dist[0][0][1 << 0] = 1;
	queue<pair<int, pair<int, int> > > q;
	q.push({0, });
}
int main(){

}