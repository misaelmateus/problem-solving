//   Author : Misael Mateus 
//   Submission date: 2017-04-16 22:16:12
#include<bits/stdc++.h>
using namespace std;

int v[100100];

int main(){
	v[1] = 1;
	for(int i = 2; i < 100100; i++)
		if(!v[i])
			for(int j = i; j < 100100; j+=i)
				v[j] = i;

	int n, k;
	cin >> n >> k;
	int K = k;
	k--;
	vector<int> list;
	while(k--){
		if(n == 1) break;
		list.push_back(v[n]);
		n/=v[n];
	}
	if(list.size() != K-1 || n == 1) cout << -1 << endl;
	else{
		for(int i = 0; i < K-1; i++) cout << list[i] << " ";
		cout << n << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

int v[100100];

int main(){
	v[1] = 1;
	for(int i = 2; i < 100100; i++)
		if(!v[i])
			for(int j = i; j < 100100; j+=i)
				v[j] = i;

	int n, k;
	cin >> n >> k;
	int K = k;
	k--;
	vector<int> list;
	while(k--){
		if(n == 1) break;
		list.push_back(v[n]);
		n/=v[n];
	}
	if(list.size() != K-1 || n == 1) cout << -1 << endl;
	else{
		for(int i = 0; i < K-1; i++) cout << list[i] << " ";
		cout << n << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

int v[100100];

int main(){
	v[1] = 1;
	for(int i = 2; i < 100100; i++)
		if(!v[i])
			for(int j = i; j < 100100; j+=i)
				v[j] = i;

	int n, k;
	cin >> n >> k;
	int K = k;
	k--;
	vector<int> list;
	while(k--){
		if(n == 1) break;
		list.push_back(v[n]);
		n/=v[n];
	}
	if(list.size() != K-1 || n == 1) cout << -1 << endl;
	else{
		for(int i = 0; i < K-1; i++) cout << list[i] << " ";
		cout << n << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

int v[100100];

int main(){
	v[1] = 1;
	for(int i = 2; i < 100100; i++)
		if(!v[i])
			for(int j = i; j < 100100; j+=i)
				v[j] = i;

	int n, k;
	cin >> n >> k;
	int K = k;
	k--;
	vector<int> list;
	while(k--){
		if(n == 1) break;
		list.push_back(v[n]);
		n/=v[n];
	}
	if(list.size() != K-1 || n == 1) cout << -1 << endl;
	else{
		for(int i = 0; i < K-1; i++) cout << list[i] << " ";
		cout << n << endl;
	}
}

