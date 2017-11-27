//   Author : Misael Mateus 
//   Submission date: 2017-08-23 19:59:19
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > v1(n);
	vector<int> v2(n), v3(n);
	for(int i = 0; i < n; i++)
		cin >> v2[i];
	for(int i = 0; i < n; i++){
		cin >> v1[i].first;
		v1[i].second = i;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	for(int i = 0; i < n; i++){
		v3[v1[i].second] = v2[i];
	}

	for(int i = 0; i < n; i++)
		cout << v3[i] << " ";
	cout << endl;
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > v1(n);
	vector<int> v2(n), v3(n);
	for(int i = 0; i < n; i++)
		cin >> v2[i];
	for(int i = 0; i < n; i++){
		cin >> v1[i].first;
		v1[i].second = i;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	for(int i = 0; i < n; i++){
		v3[v1[i].second] = v2[i];
	}

	for(int i = 0; i < n; i++)
		cout << v3[i] << " ";
	cout << endl;
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > v1(n);
	vector<int> v2(n), v3(n);
	for(int i = 0; i < n; i++)
		cin >> v2[i];
	for(int i = 0; i < n; i++){
		cin >> v1[i].first;
		v1[i].second = i;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	for(int i = 0; i < n; i++){
		v3[v1[i].second] = v2[i];
	}

	for(int i = 0; i < n; i++)
		cout << v3[i] << " ";
	cout << endl;
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > v1(n);
	vector<int> v2(n), v3(n);
	for(int i = 0; i < n; i++)
		cin >> v2[i];
	for(int i = 0; i < n; i++){
		cin >> v1[i].first;
		v1[i].second = i;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	for(int i = 0; i < n; i++){
		v3[v1[i].second] = v2[i];
	}

	for(int i = 0; i < n; i++)
		cout << v3[i] << " ";
	cout << endl;
	return 0;
}