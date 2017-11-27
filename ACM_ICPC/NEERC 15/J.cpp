#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n;
cin>>n;
int v[n];
int i;
for(i=0;i<n;i++)
	cin>>v[i];
int v2[n];
for(i=0;i<n;i++)
	v2[i]=v[i];
sort(v,v+n);
int cont=0;
for(i=0;i<n;i++){
	if(v2[i]!=v[i]){
		cont++;
	}
}
int resp[cont];
cout<< cont<<endl;
for(i=0;i<n;i++){
	if(v2[i]!=v[i])
		resp[i]=v2[i];;
}
sort(resp,resp+cont);
for(i=0;i<n;i++){
	cout<<resp[i];
	if(i!=n-1)
		cout<<" ";
}
cout<<endl;
return 0;
}