//   Author : Misael Mateus 
//   Submission date: 2016-08-24 22:07:42
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int a = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'a'){
			if(a == 0)
				continue;
			if(a == 1)
				break;
		}
		else{
			a = 1;
			s[i] = (char)((int)(s[i] - 1) );			
		}
		
	}
	
	if(a == 0){
		s[ s.size() - 1 ] = 'z';
	}
	cout << s << endl;
	
	return 0;
}
