#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int v[n],i;
	for(i=0;i<n;i++ ){
		cin>> v[i];
	}
	for(i=0;i<n;i++ ){
		for(int j=i;j<n;j++ ){
			if(v[j]<v[i]){
			int aux=v[j];
			v[j]=v[i];
			v[i]=aux;
			}
		}
	}
	return 0;
	}