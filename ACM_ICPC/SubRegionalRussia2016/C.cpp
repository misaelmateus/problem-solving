#include <bits/stdc++.h>
#define ii pair<int, int>

using namespace std;



int main() {

	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<ii> v1(n), v2(n);
	vector<int> mark(n, -1);	

	vector<int> pos(n);
	vector<int> pos1(n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &v1[i].first, &v2[i].first);
		v1[i].second = i;
		v2[i].second = i;
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(int i = 0; i < n; i++)
		pos[v2[i].second] = i;
	for(int i = 0; i < n; i++)
		pos1[v1[i].second] = i;
	

	queue<int> q;
	for(int i = n-1; i >= 0; i--){
		if(mark[v1[i].second] != -1) continue;
		q.push(v1[i].second);
		mark[v1[i].second] = i;
		while(!q.empty()){
			int v = q.front();
			
			q.pop();
			if(v >= n){
				v-=n;
				int j = pos1[v];
				for(j++; j < n && mark[v1[j].second] == -1; j++)
					mark[v1[j].second] = i, q.push(v1[j].second);
			}
			else{
				int j = pos[v];
				
				for(j++; j < n && mark[v2[j].second] == -1; j++){
					mark[v2[j].second] = i, q.push(v2[j].second + n);
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
		printf("%d\n", mark[i]);

	return 0;
}