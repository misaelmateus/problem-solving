//   Author : Misael Mateus 
//   Submission date: 2017-11-03 22:38:42
#include<bits/stdc++.h>
using namespace std;
int mark[1001];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
		v.push_back(i);
	int num[n][6];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++)
			cin >> num[i][j], mark[num[i][j]] = 1;
	}
	if(n == 3)
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				for(int l = 0; l < 6; l++)
					mark[num[0][i]*100 + num[1][j]*10 + num[2][l]] = 1,
					mark[num[0][i]*100 + num[2][j]*10 + num[1][l]] = 1,
					mark[num[1][i]*100 + num[0][j]*10 + num[2][l]] = 1,
					mark[num[1][i]*100 + num[2][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[1][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[0][j]*10 + num[1][l]] = 1;
	if(n >= 2)
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				for(int l = 0; l < 6; l++)
					for(int k = 0; k < 6; k++)
						mark[num[i][l]*10 + num[j][k]] = 1,
						mark[num[j][l]*10 + num[i][k]] = 1;

	for(int i = 1; i <= 1000; i++){
		if(!mark[i]){
			cout << i-1 << "\n";
			return 0;
		}
	}

}#include<bits/stdc++.h>
using namespace std;
int mark[1001];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
		v.push_back(i);
	int num[n][6];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++)
			cin >> num[i][j], mark[num[i][j]] = 1;
	}
	if(n == 3)
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				for(int l = 0; l < 6; l++)
					mark[num[0][i]*100 + num[1][j]*10 + num[2][l]] = 1,
					mark[num[0][i]*100 + num[2][j]*10 + num[1][l]] = 1,
					mark[num[1][i]*100 + num[0][j]*10 + num[2][l]] = 1,
					mark[num[1][i]*100 + num[2][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[1][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[0][j]*10 + num[1][l]] = 1;
	if(n >= 2)
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				for(int l = 0; l < 6; l++)
					for(int k = 0; k < 6; k++)
						mark[num[i][l]*10 + num[j][k]] = 1,
						mark[num[j][l]*10 + num[i][k]] = 1;

	for(int i = 1; i <= 1000; i++){
		if(!mark[i]){
			cout << i-1 << "\n";
			return 0;
		}
	}

}#include<bits/stdc++.h>
using namespace std;
int mark[1001];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
		v.push_back(i);
	int num[n][6];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++)
			cin >> num[i][j], mark[num[i][j]] = 1;
	}
	if(n == 3)
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				for(int l = 0; l < 6; l++)
					mark[num[0][i]*100 + num[1][j]*10 + num[2][l]] = 1,
					mark[num[0][i]*100 + num[2][j]*10 + num[1][l]] = 1,
					mark[num[1][i]*100 + num[0][j]*10 + num[2][l]] = 1,
					mark[num[1][i]*100 + num[2][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[1][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[0][j]*10 + num[1][l]] = 1;
	if(n >= 2)
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				for(int l = 0; l < 6; l++)
					for(int k = 0; k < 6; k++)
						mark[num[i][l]*10 + num[j][k]] = 1,
						mark[num[j][l]*10 + num[i][k]] = 1;

	for(int i = 1; i <= 1000; i++){
		if(!mark[i]){
			cout << i-1 << "\n";
			return 0;
		}
	}

}#include<bits/stdc++.h>
using namespace std;
int mark[1001];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
		v.push_back(i);
	int num[n][6];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++)
			cin >> num[i][j], mark[num[i][j]] = 1;
	}
	if(n == 3)
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				for(int l = 0; l < 6; l++)
					mark[num[0][i]*100 + num[1][j]*10 + num[2][l]] = 1,
					mark[num[0][i]*100 + num[2][j]*10 + num[1][l]] = 1,
					mark[num[1][i]*100 + num[0][j]*10 + num[2][l]] = 1,
					mark[num[1][i]*100 + num[2][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[1][j]*10 + num[0][l]] = 1,
					mark[num[2][i]*100 + num[0][j]*10 + num[1][l]] = 1;
	if(n >= 2)
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				for(int l = 0; l < 6; l++)
					for(int k = 0; k < 6; k++)
						mark[num[i][l]*10 + num[j][k]] = 1,
						mark[num[j][l]*10 + num[i][k]] = 1;

	for(int i = 1; i <= 1000; i++){
		if(!mark[i]){
			cout << i-1 << "\n";
			return 0;
		}
	}

}