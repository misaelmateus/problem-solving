//   Author : Misael Mateus 
//   Submission date: 2017-03-23 21:03:34
#include<bits/stdc++.h>
#define MAXN 7010
using namespace std;

int setA[MAXN];
int setB[MAXN];
int isA[MAXN];
int isB[MAXN];
bool gr[MAXN][MAXN];
bool gr1[MAXN][MAXN];
int sz[MAXN], sz1[MAXN];
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;

	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int a;
		cin >> a;
		setA[a] = 1;
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		int a;
		cin >> a;
		setB[a] = 1;
	}
	isA[1] = isB[1] = 1;
	for(int i = 2; i <= n; i++){
		int a = n+1 - i;
		int b = 2*n + 1 - i;
		if(setA[a] || (b < n && setA[b]))
			isA[i] = 1;
		if(setB[a] || (b < n && setB[b]))
			isB[i] = 1;
	
	}
	 queue<int> q;
	for(int i = 2; i <= n; i++){
		if(isA[i]){
			q.push(i);
			continue;
		}
		for(int j = 2; j <= n; j++){
			if(isB[j] != 1 ){
				int d = j - i;
				if(d < 0)
					d += n;
				if(setA[d])
					gr[i][j] = 1, sz[i]++;
			}
		}
		if(sz[i] == 0){
			q.push(i);
			isA[i] = -1;
		}

	}
	for(int i = 2; i <= n; i++){
		if(isB[i]){
			q.push(n+i);
			continue;
		}
		for(int j = 2; j <= n; j++){
			if(isA[j] != 1 ){
				int d = j - i;
				if(d < 0)
					d += n;
				if(setB[d])
					gr1[i][j] = 1, sz1[i]++;
			}
		}
		if(sz1[i] == 0){
			q.push(n+i);
			isB[i] = -1;
		}

	}

	while(!q.empty()){
		int a = q.front();
		q.pop();
		if(a <= n){
			for(int i = 1; i <= n; i++){
				if(isB[i] != 0)
					continue;
				if(gr1[i][a]) {
					if(isA[a] == 1){
						gr1[i][a] = 0, sz1[i]--;
						if(sz1[i] == 0)
							isB[i] = -1, q.push(n+i);
					}
					else
						sz1[i] = 0, isB[i] = 1, q.push(n+i);
				}
			}
		}
		else{
			a -= n;
			for(int i = 1; i <= n; i++){
				if(isA[i] != 0)
					continue;
				if(gr[i][a]) {
					if(isB[a] == 1){
						gr[i][a] = 0, sz[i]--;
						if(sz[i] == 0)
							isA[i] = -1, q.push(i);
					}
					else
						sz[i] = 0, isA[i] = 1, q.push(i);
				}
			}
		}
	}

	for(int i = 2; i <= n; i++)
		if(isA[i] == -1)
			cout << "Lose ";
		else if(isA[i] == 1)
			cout << "Win ";
		else cout << "Loop ";
	cout << "\n";

	for(int i = 2; i <= n; i++)
		if(isB[i] == -1)
			cout << "Lose ";
		else if(isB[i] == 1)
			cout << "Win ";
		else cout << "Loop ";
	cout << "\n";

	return 0;
}