//   Author : Misael Mateus 
//   Submission date: 2017-11-19 19:09:59
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int ans = 0;
	int tot = 0, cont = 0;
	for(auto u : s) if(u == 'Q') tot++;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A')
			ans += cont * (tot - cont);
		else if(s[i] == 'Q')
			cont++;
	}

	cout << ans << "\n";

}#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int ans = 0;
	int tot = 0, cont = 0;
	for(auto u : s) if(u == 'Q') tot++;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A')
			ans += cont * (tot - cont);
		else if(s[i] == 'Q')
			cont++;
	}

	cout << ans << "\n";

}#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int ans = 0;
	int tot = 0, cont = 0;
	for(auto u : s) if(u == 'Q') tot++;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A')
			ans += cont * (tot - cont);
		else if(s[i] == 'Q')
			cont++;
	}

	cout << ans << "\n";

}#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int ans = 0;
	int tot = 0, cont = 0;
	for(auto u : s) if(u == 'Q') tot++;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A')
			ans += cont * (tot - cont);
		else if(s[i] == 'Q')
			cont++;
	}

	cout << ans << "\n";

}