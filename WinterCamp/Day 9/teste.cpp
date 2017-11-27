#include<bits/stdc++.h>
using namespace std;
int test(int p){
	for(int i = 2; i*i <= p; i++)
		if(p % i == 0)
			return 0;
	return 1;
}

int main(){
	
}