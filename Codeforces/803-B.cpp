//   Author : Misael Mateus 
//   Submission date: 2017-04-30 02:10:45
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
using namespace std;
int main(){
	int n;
	cin >> n;
	int dist[n], num;
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	rep(i, n){
		cin >> num;
		if(!num) 
			dist[i] = 0, q.push(i);
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now && dist[now-1] == -1)
			dist[now-1] = dist[now] + 1, q.push(now-1);
		if(now + 1 < n && dist[now+1] == -1)
			dist[now+1] = dist[now] + 1, q.push(now+1);
	}

	rep(i, n) cout << dist[i] << " ";
	cout << "\n";

	return 0;
}