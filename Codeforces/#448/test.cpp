#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<string,int>> alunos;
	int a,b,i;
	for(i=0;i<n;i++){
		cin>>a,b;
		alunos.push_back(make_pair(b,a));
	}
	sort(alunos.begin(),alunos.end());
	vector<int> times[m];
	int j = 0;
	for(i=0;i<n;i++){
		time[j].push_back(alunos.second) 
		j++;
		if(j>=m)	
			j=0;
	}
	for(i=0;i<m;i++){
		cout<< "Time " << i+1;
		for(int j=0;i<time[m].size();j++])
			cout<< time[m][i]<<endl;
	}
	return 0;
}