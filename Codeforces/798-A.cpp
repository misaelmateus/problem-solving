//   Author : Misael Mateus 
//   Submission date: 2017-04-21 20:02:30
#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int cont = 0;
	string s;
	cin >> s;

	rp(i, s.size()){
		if(s[i] != s[s.size() - 1 - i])
			cont++;
	}
	cont /= 2;

	if(cont == 1 || (cont == 0 && s.size() % 2 == 1)){
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int cont = 0;
	string s;
	cin >> s;

	rp(i, s.size()){
		if(s[i] != s[s.size() - 1 - i])
			cont++;
	}
	cont /= 2;

	if(cont == 1 || (cont == 0 && s.size() % 2 == 1)){
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int cont = 0;
	string s;
	cin >> s;

	rp(i, s.size()){
		if(s[i] != s[s.size() - 1 - i])
			cont++;
	}
	cont /= 2;

	if(cont == 1 || (cont == 0 && s.size() % 2 == 1)){
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int cont = 0;
	string s;
	cin >> s;

	rp(i, s.size()){
		if(s[i] != s[s.size() - 1 - i])
			cont++;
	}
	cont /= 2;

	if(cont == 1 || (cont == 0 && s.size() % 2 == 1)){
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}