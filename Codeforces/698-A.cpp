//   Author : Misael Mateus 
//   Submission date: 2017-03-17 16:08:00
#include<bits/stdc++.h>
#define MAX 1000000
#define ll long long
using namespace std;
int r[200][3];
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			if(j > 0 && v[i] == j)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 0)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 1)
				r[i][j] = r[i+1][1];
			else if(v[i] == 2)
				r[i][j] = r[i+1][2];
			else{
				r[i][j] = 1 + r[i+1][0];
				if(j != 2)
					r[i][j] = min(r[i][j], r[i+1][2]);
				if(j != 1)
					r[i][j] = min(r[i][j], r[i+1][1]);
			}

		}
	}

	cout << min(r[0][0], min(r[0][1], r[0][2])) << endl;

}#include<bits/stdc++.h>
#define MAX 1000000
#define ll long long
using namespace std;
int r[200][3];
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			if(j > 0 && v[i] == j)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 0)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 1)
				r[i][j] = r[i+1][1];
			else if(v[i] == 2)
				r[i][j] = r[i+1][2];
			else{
				r[i][j] = 1 + r[i+1][0];
				if(j != 2)
					r[i][j] = min(r[i][j], r[i+1][2]);
				if(j != 1)
					r[i][j] = min(r[i][j], r[i+1][1]);
			}

		}
	}

	cout << min(r[0][0], min(r[0][1], r[0][2])) << endl;

}#include<bits/stdc++.h>
#define MAX 1000000
#define ll long long
using namespace std;
int r[200][3];
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			if(j > 0 && v[i] == j)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 0)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 1)
				r[i][j] = r[i+1][1];
			else if(v[i] == 2)
				r[i][j] = r[i+1][2];
			else{
				r[i][j] = 1 + r[i+1][0];
				if(j != 2)
					r[i][j] = min(r[i][j], r[i+1][2]);
				if(j != 1)
					r[i][j] = min(r[i][j], r[i+1][1]);
			}

		}
	}

	cout << min(r[0][0], min(r[0][1], r[0][2])) << endl;

}#include<bits/stdc++.h>
#define MAX 1000000
#define ll long long
using namespace std;
int r[200][3];
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			if(j > 0 && v[i] == j)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 0)
				r[i][j] = 1 + r[i+1][0];
			else if(v[i] == 1)
				r[i][j] = r[i+1][1];
			else if(v[i] == 2)
				r[i][j] = r[i+1][2];
			else{
				r[i][j] = 1 + r[i+1][0];
				if(j != 2)
					r[i][j] = min(r[i][j], r[i+1][2]);
				if(j != 1)
					r[i][j] = min(r[i][j], r[i+1][1]);
			}

		}
	}

	cout << min(r[0][0], min(r[0][1], r[0][2])) << endl;

}