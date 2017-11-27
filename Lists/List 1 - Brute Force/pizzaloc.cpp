#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int dist2(ii a, ii b){
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
int main()
{
	int K, R, M;
	cin >> K >> R >> M;
	ii places[M];
	for(int i = 0; i < M; i++) cin >> places[i].first >> places[i].second;

	int N;
	cin >> N;
	ii sol[N];
	int q[N];
	for(int i = 0; i < N; i++) cin >> sol[i].first >> sol[i].second >> q[i];

	vector<int> dist(N, 0);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(dist2(places[j], sol[i]) <= R*R)
				dist[i] += (1 << j);

	int ans = 0;
	for(int mask = 1; mask < (1 << M); mask++){
		int t = __builtin_popcount((unsigned int)mask);
		if(t > K) continue;
		int count = 0;

		for(int i = 0; i < N; i++)
			if(dist[i] & mask)
				count += q[i];

		if(count > ans) ans = count;
	}

	cout << ans << endl;
}