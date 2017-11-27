#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);	
	int T;
	while(cin >> T){
		int aux, cont = 0;
		for(int i = 0; i < 5; i++){
			cin >> aux;
			cont += (aux == T);
		}
		cout << cont << "\n";
	}

}