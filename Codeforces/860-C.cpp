//   Author : Misael Mateus 
//   Submission date: 2017-09-18 14:39:56
#include<bits/stdc++.h>

#define MAXN 100010
using namespace std;

map<string, int> mapa;
vector<int> holes[2], wrong[2];
vector<string> aleatorios[2];
string string_diff;

int t[MAXN];
int toNum(string s){
	if(s[0] == '0' || s.size() > 6)
		return -1;
	int num = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] > '9' || s[i] < '0') return -1;
		num = num*10 + (int)(s[i] - '0');
	}

	return num;
}

string toString(int a){
	string ans = "", ans1 = "";
	while(a > 0){
		ans += (char)((a % 10) + '0');
		a /= 10;
	}
	for(int i = ans.size()-1; i >= 0; i--) ans1 += ans[i];
	return ans1;
}

void gera_diff(){
	while(1){
		string_diff = "";
		for(int i = 0; i < 6; i++){
			string_diff += ( (rand() % 24) + 'a');
		}
		if(!mapa[string_diff])
			return;
	}
}
int main(){
	srand(time(NULL));
	string_diff = "abcded";
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	string aux;
	int type;
	int q = 0;
	for(int i = 1; i <= n; i++) t[i] = -1;
	for(int i = 0; i < n; i++){
		cin >> aux >> type;
		mapa[aux] = 1;
		q += type;
		int num = toNum(aux);
		if(num == -1 || num > n || num <= 0)
			aleatorios[type].push_back(aux);
		else t[num] = type;

	}
	for(int i  =1; i <= n; i++){

		if(t[i] == -1)
			holes[(int)(i <= q)].push_back(i);		
		if(t[i] == 0 && i <= q)
			wrong[0].push_back(i);
		else if(t[i] == 1 && i > q)
			wrong[1].push_back(i);
	}
	vector<pair<string, string> >moves;
	if( (wrong[0].size() && !holes[0].size()) && (wrong[1].size() && !holes[1].size())){
			if(wrong[0].size()){
				holes[1].push_back(wrong[0][wrong[0].size()-1]);
				moves.push_back({toString(wrong[0][wrong[0].size()-1]), string_diff});
				wrong[0].pop_back();
				aleatorios[0].push_back(string_diff);
			}
			else{
				holes[0].push_back(wrong[1][wrong[1].size()-1]);
				moves.push_back({toString(wrong[1][wrong[1].size()-1]), string_diff});
				wrong[1].pop_back();	
				aleatorios[1].push_back(string_diff);
			}
	}
	while(wrong[0].size() || wrong[1].size() ){
		
		if(wrong[0].size() && holes[0].size()){
				moves.push_back({toString(wrong[0].back()), toString(holes[0].back())});
				holes[1].push_back(wrong[0].back());
				wrong[0].pop_back();
				holes[0].pop_back();
			
		}
		else{
			moves.push_back({toString(wrong[1].back()), toString(holes[1].back())});
			holes[0].push_back(wrong[1].back());
			wrong[1].pop_back();
			holes[1].pop_back();
				
		}
	}
	for(int l = 0; l < 2; l++)
		for(int i =0; i < aleatorios[l].size(); i++)
			moves.push_back({aleatorios[l][i], toString(holes[l][i])});

	cout << moves.size() <<"\n";
	for(int i = 0; i < moves.size(); i++){
		cout << "move " << moves[i].first << " " << moves[i].second << "\n";
	}

	return 0;
}#include<bits/stdc++.h>

#define MAXN 100010
using namespace std;

map<string, int> mapa;
vector<int> holes[2], wrong[2];
vector<string> aleatorios[2];
string string_diff;

int t[MAXN];
int toNum(string s){
	if(s[0] == '0' || s.size() > 6)
		return -1;
	int num = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] > '9' || s[i] < '0') return -1;
		num = num*10 + (int)(s[i] - '0');
	}

	return num;
}

string toString(int a){
	string ans = "", ans1 = "";
	while(a > 0){
		ans += (char)((a % 10) + '0');
		a /= 10;
	}
	for(int i = ans.size()-1; i >= 0; i--) ans1 += ans[i];
	return ans1;
}

void gera_diff(){
	while(1){
		string_diff = "";
		for(int i = 0; i < 6; i++){
			string_diff += ( (rand() % 24) + 'a');
		}
		if(!mapa[string_diff])
			return;
	}
}
int main(){
	srand(time(NULL));
	string_diff = "abcded";
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	string aux;
	int type;
	int q = 0;
	for(int i = 1; i <= n; i++) t[i] = -1;
	for(int i = 0; i < n; i++){
		cin >> aux >> type;
		mapa[aux] = 1;
		q += type;
		int num = toNum(aux);
		if(num == -1 || num > n || num <= 0)
			aleatorios[type].push_back(aux);
		else t[num] = type;

	}
	for(int i  =1; i <= n; i++){

		if(t[i] == -1)
			holes[(int)(i <= q)].push_back(i);		
		if(t[i] == 0 && i <= q)
			wrong[0].push_back(i);
		else if(t[i] == 1 && i > q)
			wrong[1].push_back(i);
	}
	vector<pair<string, string> >moves;
	if( (wrong[0].size() && !holes[0].size()) && (wrong[1].size() && !holes[1].size())){
			if(wrong[0].size()){
				holes[1].push_back(wrong[0][wrong[0].size()-1]);
				moves.push_back({toString(wrong[0][wrong[0].size()-1]), string_diff});
				wrong[0].pop_back();
				aleatorios[0].push_back(string_diff);
			}
			else{
				holes[0].push_back(wrong[1][wrong[1].size()-1]);
				moves.push_back({toString(wrong[1][wrong[1].size()-1]), string_diff});
				wrong[1].pop_back();	
				aleatorios[1].push_back(string_diff);
			}
	}
	while(wrong[0].size() || wrong[1].size() ){
		
		if(wrong[0].size() && holes[0].size()){
				moves.push_back({toString(wrong[0].back()), toString(holes[0].back())});
				holes[1].push_back(wrong[0].back());
				wrong[0].pop_back();
				holes[0].pop_back();
			
		}
		else{
			moves.push_back({toString(wrong[1].back()), toString(holes[1].back())});
			holes[0].push_back(wrong[1].back());
			wrong[1].pop_back();
			holes[1].pop_back();
				
		}
	}
	for(int l = 0; l < 2; l++)
		for(int i =0; i < aleatorios[l].size(); i++)
			moves.push_back({aleatorios[l][i], toString(holes[l][i])});

	cout << moves.size() <<"\n";
	for(int i = 0; i < moves.size(); i++){
		cout << "move " << moves[i].first << " " << moves[i].second << "\n";
	}

	return 0;
}#include<bits/stdc++.h>

#define MAXN 100010
using namespace std;

map<string, int> mapa;
vector<int> holes[2], wrong[2];
vector<string> aleatorios[2];
string string_diff;

int t[MAXN];
int toNum(string s){
	if(s[0] == '0' || s.size() > 6)
		return -1;
	int num = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] > '9' || s[i] < '0') return -1;
		num = num*10 + (int)(s[i] - '0');
	}

	return num;
}

string toString(int a){
	string ans = "", ans1 = "";
	while(a > 0){
		ans += (char)((a % 10) + '0');
		a /= 10;
	}
	for(int i = ans.size()-1; i >= 0; i--) ans1 += ans[i];
	return ans1;
}

void gera_diff(){
	while(1){
		string_diff = "";
		for(int i = 0; i < 6; i++){
			string_diff += ( (rand() % 24) + 'a');
		}
		if(!mapa[string_diff])
			return;
	}
}
int main(){
	srand(time(NULL));
	string_diff = "abcded";
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	string aux;
	int type;
	int q = 0;
	for(int i = 1; i <= n; i++) t[i] = -1;
	for(int i = 0; i < n; i++){
		cin >> aux >> type;
		mapa[aux] = 1;
		q += type;
		int num = toNum(aux);
		if(num == -1 || num > n || num <= 0)
			aleatorios[type].push_back(aux);
		else t[num] = type;

	}
	for(int i  =1; i <= n; i++){

		if(t[i] == -1)
			holes[(int)(i <= q)].push_back(i);		
		if(t[i] == 0 && i <= q)
			wrong[0].push_back(i);
		else if(t[i] == 1 && i > q)
			wrong[1].push_back(i);
	}
	vector<pair<string, string> >moves;
	if( (wrong[0].size() && !holes[0].size()) && (wrong[1].size() && !holes[1].size())){
			if(wrong[0].size()){
				holes[1].push_back(wrong[0][wrong[0].size()-1]);
				moves.push_back({toString(wrong[0][wrong[0].size()-1]), string_diff});
				wrong[0].pop_back();
				aleatorios[0].push_back(string_diff);
			}
			else{
				holes[0].push_back(wrong[1][wrong[1].size()-1]);
				moves.push_back({toString(wrong[1][wrong[1].size()-1]), string_diff});
				wrong[1].pop_back();	
				aleatorios[1].push_back(string_diff);
			}
	}
	while(wrong[0].size() || wrong[1].size() ){
		
		if(wrong[0].size() && holes[0].size()){
				moves.push_back({toString(wrong[0].back()), toString(holes[0].back())});
				holes[1].push_back(wrong[0].back());
				wrong[0].pop_back();
				holes[0].pop_back();
			
		}
		else{
			moves.push_back({toString(wrong[1].back()), toString(holes[1].back())});
			holes[0].push_back(wrong[1].back());
			wrong[1].pop_back();
			holes[1].pop_back();
				
		}
	}
	for(int l = 0; l < 2; l++)
		for(int i =0; i < aleatorios[l].size(); i++)
			moves.push_back({aleatorios[l][i], toString(holes[l][i])});

	cout << moves.size() <<"\n";
	for(int i = 0; i < moves.size(); i++){
		cout << "move " << moves[i].first << " " << moves[i].second << "\n";
	}

	return 0;
}#include<bits/stdc++.h>

#define MAXN 100010
using namespace std;

map<string, int> mapa;
vector<int> holes[2], wrong[2];
vector<string> aleatorios[2];
string string_diff;

int t[MAXN];
int toNum(string s){
	if(s[0] == '0' || s.size() > 6)
		return -1;
	int num = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] > '9' || s[i] < '0') return -1;
		num = num*10 + (int)(s[i] - '0');
	}

	return num;
}

string toString(int a){
	string ans = "", ans1 = "";
	while(a > 0){
		ans += (char)((a % 10) + '0');
		a /= 10;
	}
	for(int i = ans.size()-1; i >= 0; i--) ans1 += ans[i];
	return ans1;
}

void gera_diff(){
	while(1){
		string_diff = "";
		for(int i = 0; i < 6; i++){
			string_diff += ( (rand() % 24) + 'a');
		}
		if(!mapa[string_diff])
			return;
	}
}
int main(){
	srand(time(NULL));
	string_diff = "abcded";
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	string aux;
	int type;
	int q = 0;
	for(int i = 1; i <= n; i++) t[i] = -1;
	for(int i = 0; i < n; i++){
		cin >> aux >> type;
		mapa[aux] = 1;
		q += type;
		int num = toNum(aux);
		if(num == -1 || num > n || num <= 0)
			aleatorios[type].push_back(aux);
		else t[num] = type;

	}
	for(int i  =1; i <= n; i++){

		if(t[i] == -1)
			holes[(int)(i <= q)].push_back(i);		
		if(t[i] == 0 && i <= q)
			wrong[0].push_back(i);
		else if(t[i] == 1 && i > q)
			wrong[1].push_back(i);
	}
	vector<pair<string, string> >moves;
	if( (wrong[0].size() && !holes[0].size()) && (wrong[1].size() && !holes[1].size())){
			if(wrong[0].size()){
				holes[1].push_back(wrong[0][wrong[0].size()-1]);
				moves.push_back({toString(wrong[0][wrong[0].size()-1]), string_diff});
				wrong[0].pop_back();
				aleatorios[0].push_back(string_diff);
			}
			else{
				holes[0].push_back(wrong[1][wrong[1].size()-1]);
				moves.push_back({toString(wrong[1][wrong[1].size()-1]), string_diff});
				wrong[1].pop_back();	
				aleatorios[1].push_back(string_diff);
			}
	}
	while(wrong[0].size() || wrong[1].size() ){
		
		if(wrong[0].size() && holes[0].size()){
				moves.push_back({toString(wrong[0].back()), toString(holes[0].back())});
				holes[1].push_back(wrong[0].back());
				wrong[0].pop_back();
				holes[0].pop_back();
			
		}
		else{
			moves.push_back({toString(wrong[1].back()), toString(holes[1].back())});
			holes[0].push_back(wrong[1].back());
			wrong[1].pop_back();
			holes[1].pop_back();
				
		}
	}
	for(int l = 0; l < 2; l++)
		for(int i =0; i < aleatorios[l].size(); i++)
			moves.push_back({aleatorios[l][i], toString(holes[l][i])});

	cout << moves.size() <<"\n";
	for(int i = 0; i < moves.size(); i++){
		cout << "move " << moves[i].first << " " << moves[i].second << "\n";
	}

	return 0;
}