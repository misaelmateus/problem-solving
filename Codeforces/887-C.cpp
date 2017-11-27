//   Author : Misael Mateus 
//   Submission date: 2017-11-03 22:37:59
#include<bits/stdc++.h>
using namespace std;
int v[25];
int check(){
	for(int i = 1; i <= 21; i+=4){
		int color = v[i];
		for(int j = 1; j < 4; j++){
			if(v[i+j] != color)
				return 0;
		}
	}
	return 1;
}

void gira(vector<int> v1, int flag){
	int s[8];
	if(!flag)
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i + 2)%8]];
	else
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i - 2 + 8)%8]];
	for(int i = 0; i < 8; i++)
		v[v1[i]] = s[i];
}
int main(){
	for(int i = 1; i <= 24; i++)
		cin >> v[i];
	int flag = 0;
	
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);

	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);

	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);

	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}#include<bits/stdc++.h>
using namespace std;
int v[25];
int check(){
	for(int i = 1; i <= 21; i+=4){
		int color = v[i];
		for(int j = 1; j < 4; j++){
			if(v[i+j] != color)
				return 0;
		}
	}
	return 1;
}

void gira(vector<int> v1, int flag){
	int s[8];
	if(!flag)
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i + 2)%8]];
	else
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i - 2 + 8)%8]];
	for(int i = 0; i < 8; i++)
		v[v1[i]] = s[i];
}
int main(){
	for(int i = 1; i <= 24; i++)
		cin >> v[i];
	int flag = 0;
	
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);

	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);

	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);

	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}#include<bits/stdc++.h>
using namespace std;
int v[25];
int check(){
	for(int i = 1; i <= 21; i+=4){
		int color = v[i];
		for(int j = 1; j < 4; j++){
			if(v[i+j] != color)
				return 0;
		}
	}
	return 1;
}

void gira(vector<int> v1, int flag){
	int s[8];
	if(!flag)
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i + 2)%8]];
	else
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i - 2 + 8)%8]];
	for(int i = 0; i < 8; i++)
		v[v1[i]] = s[i];
}
int main(){
	for(int i = 1; i <= 24; i++)
		cin >> v[i];
	int flag = 0;
	
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);

	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);

	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);

	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}#include<bits/stdc++.h>
using namespace std;
int v[25];
int check(){
	for(int i = 1; i <= 21; i+=4){
		int color = v[i];
		for(int j = 1; j < 4; j++){
			if(v[i+j] != color)
				return 0;
		}
	}
	return 1;
}

void gira(vector<int> v1, int flag){
	int s[8];
	if(!flag)
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i + 2)%8]];
	else
	 for(int i = 0; i < 8; i++)
		s[i] = v[v1[(i - 2 + 8)%8]];
	for(int i = 0; i < 8; i++)
		v[v1[i]] = s[i];
}
int main(){
	for(int i = 1; i <= 24; i++)
		cin >> v[i];
	int flag = 0;
	
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 1);
	if(check()) flag = 1;
	gira({1, 3, 5, 7, 9, 11, 24, 22}, 0);
	
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 1);
	if(check()) flag = 1;
	gira({2, 4, 6, 8, 10, 12, 23, 21}, 0);
	
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 1);
	if(check()) flag = 1;
	gira({13, 14, 5, 6, 17, 18, 21, 22}, 0);

	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 1);
	if(check()) flag = 1;
	gira({15, 16, 7, 8, 19, 20, 23, 24}, 0);

	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 1);
	if(check()) flag = 1;
	gira({14, 16, 9, 10, 19, 17, 4, 3}, 0);

	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 1);
	if(check()) flag = 1;
	gira({13, 15, 11, 12, 20, 18, 2, 1}, 0);
	

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}