#include<bits/stdc++.h>
using namespace std;
int q[10];
string s;
string s1;
int flag;	
int f(int i){
	if(i == s.size())
		return true;
	if(flag == 1){
		int n = (int)(s[i] - '0');
		while(n >= 0){
			q[n]++;
			s1.push_back((char)('0' + n));
			if(q[n] <= 2 && f(i+1)){
				return true;
			}
			else{
				q[n]--;
				s1.pop_back();
				flag = 0;
				n--;
			}
		}
		return false;
	}
	else{
		int n = 9;
		for(; n>=0 && q[n] == 2; n--);
		if(n < 0) return false;
		s1.push_back((char)('0' + n));
		q[n]++;
		return f(i+1);
	}
}

int make(int i){
	if(i == s.size()-1)
		return true;
	int n = 9;
	for(; n>=0 && q[n] == 2; n--);
	if(n < 0) return true;
	s1.push_back((char)('0' + n));
	q[n]++;
	f(i+1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		s1 = "";
		flag = 1;
		memset(q, 0, sizeof(q));
		int ans = f(0);
		if(!ans){
			memset(q, 0, sizeof(q));
			s1 = "";
			make(0);
		}
		int i;
		for(i = 0; i < s1.size() && s1[i] == '0'; i++);
		for(; i < s1.size(); i++) cout << s1[i];
		cout << "\n";
	}
}