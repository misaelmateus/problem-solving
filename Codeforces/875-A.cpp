//   Author : Misael Mateus 
//   Submission date: 2017-10-16 16:37:53
#include<bits/stdc++.h>
#define readFast ios::sync_with_stdio(false)
using namespace std;

int sum_dig(int n){
	int sum = 0;
	while(n > 0){
		sum += n%10;
		n/=10;
	}
	return sum;
}
int main(){
	readFast;
	int n;
	cin >> n;
	vector<int> ans;
	for(int i = 1; n - i >= 1 && i <= 100; i++){
		if(n-i + sum_dig(n-i) == n){
			ans.push_back(n-i);
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto u : ans){
		cout << u << "\n";
	}
	return 0;
}