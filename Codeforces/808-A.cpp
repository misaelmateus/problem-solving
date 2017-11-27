//   Author : Misael Mateus 
//   Submission date: 2017-05-16 22:25:51
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int cont = 0, cont1 = 1, i;
	for(i = 0; i < s.size() && cont < 1; cont += (s[i] != '0'), i++);
	cont = 0;
	for(int j = s.size()-1; j >= i; j--) 
		cont += cont1*(int)(s[j] - '0'), cont1 *= 10;


	cout << cont1 - cont << endl;	
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int cont = 0, cont1 = 1, i;
	for(i = 0; i < s.size() && cont < 1; cont += (s[i] != '0'), i++);
	cont = 0;
	for(int j = s.size()-1; j >= i; j--) 
		cont += cont1*(int)(s[j] - '0'), cont1 *= 10;


	cout << cont1 - cont << endl;	
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int cont = 0, cont1 = 1, i;
	for(i = 0; i < s.size() && cont < 1; cont += (s[i] != '0'), i++);
	cont = 0;
	for(int j = s.size()-1; j >= i; j--) 
		cont += cont1*(int)(s[j] - '0'), cont1 *= 10;


	cout << cont1 - cont << endl;	
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int cont = 0, cont1 = 1, i;
	for(i = 0; i < s.size() && cont < 1; cont += (s[i] != '0'), i++);
	cont = 0;
	for(int j = s.size()-1; j >= i; j--) 
		cont += cont1*(int)(s[j] - '0'), cont1 *= 10;


	cout << cont1 - cont << endl;	
	return 0;
}