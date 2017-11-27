//   Author : Misael Mateus 
//   Submission date: 2017-11-11 16:22:38
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<int> v1, v2;
	for(int mask = 0; mask < (1 << (n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[l]) % m;	
		}
		v1.push_back(sum);
	}
	for(int mask = 0; mask < (1 << (n - n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n - n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[n/2 + l]) % m;	
		}
		v2.push_back(sum);
	}
	sort(v2.begin(), v2.end());
	int ans = 0;
	for(int i = 0; i < v1.size(); i++){
		int a = m - v1[i];
		auto it = lower_bound(v2.begin(), v2.end(), a);
		if(it != v2.begin()){
			it--;
			ans = max(ans, v1[i] + *it);
		}
		a = 2*m - v1[i];
		auto it2 = lower_bound(v2.begin(), v2.end(), a);
		if(it2 != v2.begin()){
			it2--;
			ans = max(ans, (v1[i] + *it2)%m);
		}
	}
	cout << ans << "\n";
}#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<int> v1, v2;
	for(int mask = 0; mask < (1 << (n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[l]) % m;	
		}
		v1.push_back(sum);
	}
	for(int mask = 0; mask < (1 << (n - n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n - n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[n/2 + l]) % m;	
		}
		v2.push_back(sum);
	}
	sort(v2.begin(), v2.end());
	int ans = 0;
	for(int i = 0; i < v1.size(); i++){
		int a = m - v1[i];
		auto it = lower_bound(v2.begin(), v2.end(), a);
		if(it != v2.begin()){
			it--;
			ans = max(ans, v1[i] + *it);
		}
		a = 2*m - v1[i];
		auto it2 = lower_bound(v2.begin(), v2.end(), a);
		if(it2 != v2.begin()){
			it2--;
			ans = max(ans, (v1[i] + *it2)%m);
		}
	}
	cout << ans << "\n";
}#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<int> v1, v2;
	for(int mask = 0; mask < (1 << (n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[l]) % m;	
		}
		v1.push_back(sum);
	}
	for(int mask = 0; mask < (1 << (n - n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n - n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[n/2 + l]) % m;	
		}
		v2.push_back(sum);
	}
	sort(v2.begin(), v2.end());
	int ans = 0;
	for(int i = 0; i < v1.size(); i++){
		int a = m - v1[i];
		auto it = lower_bound(v2.begin(), v2.end(), a);
		if(it != v2.begin()){
			it--;
			ans = max(ans, v1[i] + *it);
		}
		a = 2*m - v1[i];
		auto it2 = lower_bound(v2.begin(), v2.end(), a);
		if(it2 != v2.begin()){
			it2--;
			ans = max(ans, (v1[i] + *it2)%m);
		}
	}
	cout << ans << "\n";
}#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<int> v1, v2;
	for(int mask = 0; mask < (1 << (n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[l]) % m;	
		}
		v1.push_back(sum);
	}
	for(int mask = 0; mask < (1 << (n - n/2)); mask++){
		int sum = 0;
		for(int l = 0; l < (n - n/2); l++){
			if(mask & (1 << l))
				sum = (sum + v[n/2 + l]) % m;	
		}
		v2.push_back(sum);
	}
	sort(v2.begin(), v2.end());
	int ans = 0;
	for(int i = 0; i < v1.size(); i++){
		int a = m - v1[i];
		auto it = lower_bound(v2.begin(), v2.end(), a);
		if(it != v2.begin()){
			it--;
			ans = max(ans, v1[i] + *it);
		}
		a = 2*m - v1[i];
		auto it2 = lower_bound(v2.begin(), v2.end(), a);
		if(it2 != v2.begin()){
			it2--;
			ans = max(ans, (v1[i] + *it2)%m);
		}
	}
	cout << ans << "\n";
}