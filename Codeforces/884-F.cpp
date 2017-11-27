//   Author : Misael Mateus 
//   Submission date: 2017-10-28 20:05:44
#include<bits/stdc++.h>
using namespace std;
int cont[26];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int b[n];
	int ans = 0;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		ans += b[i];
		if(s[i] == s[n - i - 1]){
			if(b[i] < b[n-1-i])
				cont[s[i] - 'a']++, s[i] = '-', ans -= b[i];
			else cont[s[i] - 'a']++, s[n - 1 - i] = '-', ans -= b[n - 1 - i];
		}
	}

	int ma = 0, tot = 0;
	int i_ma = -1;
	for(int i = 0; i < 26; i++){

		tot += cont[i];
		if(cont[i] > ma)
			ma = cont[i], i_ma = i;
	}

	while(ma > tot - ma){
		int id = -1;
		int mi = 1e9;
		for(int i = 0; i < n; i++){
			if(s[i] != '-' && (int)((s[i] - 'a') != i_ma && (int)(s[n-1-i] - 'a') != i_ma)&& b[i] < mi)
				mi = b[i], id = i;
		}
		if(id == -1) while(true);
		s[id] = '-';
		tot++;
		ans -= b[id];
	}

	if(tot % 2 != 0){
		int id = 0;
		int mi = 1e9;
		for(int i = 0; i < n; i++){

			if(s[i] != '-' && b[i] < mi)
				mi = b[i], id = i;
		}
		s[id] = '-';
		tot++;
		//ans -= b[id];
	}

	printf("%d\n", ans);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int cont[26];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int b[n];
	int ans = 0;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		ans += b[i];
		if(s[i] == s[n - i - 1]){
			if(b[i] < b[n-1-i])
				cont[s[i] - 'a']++, s[i] = '-', ans -= b[i];
			else cont[s[i] - 'a']++, s[n - 1 - i] = '-', ans -= b[n - 1 - i];
		}
	}

	int ma = 0, tot = 0;
	int i_ma = -1;
	for(int i = 0; i < 26; i++){

		tot += cont[i];
		if(cont[i] > ma)
			ma = cont[i], i_ma = i;
	}

	while(ma > tot - ma){
		int id = -1;
		int mi = 1e9;
		for(int i = 0; i < n; i++){
			if(s[i] != '-' && (int)((s[i] - 'a') != i_ma && (int)(s[n-1-i] - 'a') != i_ma)&& b[i] < mi)
				mi = b[i], id = i;
		}
		if(id == -1) while(true);
		s[id] = '-';
		tot++;
		ans -= b[id];
	}

	if(tot % 2 != 0){
		int id = 0;
		int mi = 1e9;
		for(int i = 0; i < n; i++){

			if(s[i] != '-' && b[i] < mi)
				mi = b[i], id = i;
		}
		s[id] = '-';
		tot++;
		//ans -= b[id];
	}

	printf("%d\n", ans);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int cont[26];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int b[n];
	int ans = 0;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		ans += b[i];
		if(s[i] == s[n - i - 1]){
			if(b[i] < b[n-1-i])
				cont[s[i] - 'a']++, s[i] = '-', ans -= b[i];
			else cont[s[i] - 'a']++, s[n - 1 - i] = '-', ans -= b[n - 1 - i];
		}
	}

	int ma = 0, tot = 0;
	int i_ma = -1;
	for(int i = 0; i < 26; i++){

		tot += cont[i];
		if(cont[i] > ma)
			ma = cont[i], i_ma = i;
	}

	while(ma > tot - ma){
		int id = -1;
		int mi = 1e9;
		for(int i = 0; i < n; i++){
			if(s[i] != '-' && (int)((s[i] - 'a') != i_ma && (int)(s[n-1-i] - 'a') != i_ma)&& b[i] < mi)
				mi = b[i], id = i;
		}
		if(id == -1) while(true);
		s[id] = '-';
		tot++;
		ans -= b[id];
	}

	if(tot % 2 != 0){
		int id = 0;
		int mi = 1e9;
		for(int i = 0; i < n; i++){

			if(s[i] != '-' && b[i] < mi)
				mi = b[i], id = i;
		}
		s[id] = '-';
		tot++;
		//ans -= b[id];
	}

	printf("%d\n", ans);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int cont[26];
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int b[n];
	int ans = 0;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		ans += b[i];
		if(s[i] == s[n - i - 1]){
			if(b[i] < b[n-1-i])
				cont[s[i] - 'a']++, s[i] = '-', ans -= b[i];
			else cont[s[i] - 'a']++, s[n - 1 - i] = '-', ans -= b[n - 1 - i];
		}
	}

	int ma = 0, tot = 0;
	int i_ma = -1;
	for(int i = 0; i < 26; i++){

		tot += cont[i];
		if(cont[i] > ma)
			ma = cont[i], i_ma = i;
	}

	while(ma > tot - ma){
		int id = -1;
		int mi = 1e9;
		for(int i = 0; i < n; i++){
			if(s[i] != '-' && (int)((s[i] - 'a') != i_ma && (int)(s[n-1-i] - 'a') != i_ma)&& b[i] < mi)
				mi = b[i], id = i;
		}
		if(id == -1) while(true);
		s[id] = '-';
		tot++;
		ans -= b[id];
	}

	if(tot % 2 != 0){
		int id = 0;
		int mi = 1e9;
		for(int i = 0; i < n; i++){

			if(s[i] != '-' && b[i] < mi)
				mi = b[i], id = i;
		}
		s[id] = '-';
		tot++;
		//ans -= b[id];
	}

	printf("%d\n", ans);
	return 0;
}