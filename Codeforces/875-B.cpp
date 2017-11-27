//   Author : Misael Mateus 
//   Submission date: 2017-10-16 19:15:05
#include<bits/stdc++.h>
#define MAXN 300100
#define readFast ios::sync_with_stdio(false)
using namespace std;
int v[MAXN];
int main(){
	readFast;
	int n;
	cin >> n;
	int cont = 0;
	cout << "1 ";
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		v[p] = 1;
		if(p == n - cont)
			while(v[p--])
				cont++;
		cout << i + 2 - cont << " ";
	}
	return 0;
}#include<bits/stdc++.h>
#define MAXN 300100
#define readFast ios::sync_with_stdio(false)
using namespace std;
int v[MAXN];
int main(){
	readFast;
	int n;
	cin >> n;
	int cont = 0;
	cout << "1 ";
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		v[p] = 1;
		if(p == n - cont)
			while(v[p--])
				cont++;
		cout << i + 2 - cont << " ";
	}
	return 0;
}#include<bits/stdc++.h>
#define MAXN 300100
#define readFast ios::sync_with_stdio(false)
using namespace std;
int v[MAXN];
int main(){
	readFast;
	int n;
	cin >> n;
	int cont = 0;
	cout << "1 ";
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		v[p] = 1;
		if(p == n - cont)
			while(v[p--])
				cont++;
		cout << i + 2 - cont << " ";
	}
	return 0;
}#include<bits/stdc++.h>
#define MAXN 300100
#define readFast ios::sync_with_stdio(false)
using namespace std;
int v[MAXN];
int main(){
	readFast;
	int n;
	cin >> n;
	int cont = 0;
	cout << "1 ";
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		v[p] = 1;
		if(p == n - cont)
			while(v[p--])
				cont++;
		cout << i + 2 - cont << " ";
	}
	return 0;
}