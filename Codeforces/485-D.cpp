//   Author : Misael Mateus 
//   Submission date: 2017-02-09 05:05:41
#include<bits/stdc++.h>
#define MAXV 1000010
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int ans = 0;
	for(int i = 0; i < N; i++){
		if(i > 0 && a[i] == a[i-1]) continue;
		for(int j = 2; a[i]*j < MAXV; j++){
			auto it = lower_bound(a.begin(), a.end(), a[i]*j);
			if(it == a.end()) continue;
			it--;
			if(*it >= a[i])
				ans = max(ans, *it - a[i]*(j-1));
		}
		ans = max(ans, a[N-1]%a[i]);
	}

	cout << ans << endl;
	return 0;
}