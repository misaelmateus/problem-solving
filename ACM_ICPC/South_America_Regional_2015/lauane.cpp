#include<iostream>
using namespace std;

int main(){
	int y,n;
	int i,x=0;
	while(cin>>y>>n && y!=0 && n!=0){
		x++;
		int a[y+1];
		for(i=0;i<y+1;i++)
			a[i]=0;
		int a1[n],a2[n];
		for(i=0;i<n;i++){
			cin>>a1[i]>>a2[i];
			a[a1[i]]++; a[a2[i]]++;
		}
		int maior =0;
		for(i=0;i<y+1;i++){
			if(maior<a[i])
				maior= a[i];
		}
		cout<< "Teste "<< x<<endl;
		for(i=0;i<y+1;i++){
			if(a[i]==maior)
				cout<< i<<" ";
		}
		cout<<endl;
	}

	return 0;
}