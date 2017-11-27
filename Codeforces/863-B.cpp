//   Author : Misael Mateus 
//   Submission date: 2017-09-22 20:22:45
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	n *= 2;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			vector<int> v1;
			for(int l = 0; l < n; l++){
				if(l != i && l != j) v1.push_back(v[l]);
			}
			int sum = 0;
			for(int i = 0; i < n-2; i+=2)
				sum += (v1[i+1] - v1[i]);
			ans =min (ans, sum);
		}
	}
	cout << ans << "\n";
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	n *= 2;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			vector<int> v1;
			for(int l = 0; l < n; l++){
				if(l != i && l != j) v1.push_back(v[l]);
			}
			int sum = 0;
			for(int i = 0; i < n-2; i+=2)
				sum += (v1[i+1] - v1[i]);
			ans =min (ans, sum);
		}
	}
	cout << ans << "\n";
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	n *= 2;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			vector<int> v1;
			for(int l = 0; l < n; l++){
				if(l != i && l != j) v1.push_back(v[l]);
			}
			int sum = 0;
			for(int i = 0; i < n-2; i+=2)
				sum += (v1[i+1] - v1[i]);
			ans =min (ans, sum);
		}
	}
	cout << ans << "\n";
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	n *= 2;
	int v[n];
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			vector<int> v1;
			for(int l = 0; l < n; l++){
				if(l != i && l != j) v1.push_back(v[l]);
			}
			int sum = 0;
			for(int i = 0; i < n-2; i+=2)
				sum += (v1[i+1] - v1[i]);
			ans =min (ans, sum);
		}
	}
	cout << ans << "\n";
}