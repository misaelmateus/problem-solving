//   Author : Misael Mateus 
//   Submission date: 2017-01-19 20:52:12
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    
    map<char, int> mapa;
    for(int i = 4; i < s.size(); i++){
        if(s[i] == '!')
            continue;
        for(int j = i - 4; j >= 0 && s[j] == '!'; j-=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    for(int i = s.size()-5; i >= 0; i--){
        if(s[i] == '!')
            continue;
        for(int j = i + 4; j < s.size() && s[j] == '!'; j+=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    cout << mapa['R'] << " " << mapa['B'] << " " << mapa['Y'] << " " << mapa['G'] << endl;
}#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    
    map<char, int> mapa;
    for(int i = 4; i < s.size(); i++){
        if(s[i] == '!')
            continue;
        for(int j = i - 4; j >= 0 && s[j] == '!'; j-=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    for(int i = s.size()-5; i >= 0; i--){
        if(s[i] == '!')
            continue;
        for(int j = i + 4; j < s.size() && s[j] == '!'; j+=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    cout << mapa['R'] << " " << mapa['B'] << " " << mapa['Y'] << " " << mapa['G'] << endl;
}#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    
    map<char, int> mapa;
    for(int i = 4; i < s.size(); i++){
        if(s[i] == '!')
            continue;
        for(int j = i - 4; j >= 0 && s[j] == '!'; j-=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    for(int i = s.size()-5; i >= 0; i--){
        if(s[i] == '!')
            continue;
        for(int j = i + 4; j < s.size() && s[j] == '!'; j+=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    cout << mapa['R'] << " " << mapa['B'] << " " << mapa['Y'] << " " << mapa['G'] << endl;
}#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    
    map<char, int> mapa;
    for(int i = 4; i < s.size(); i++){
        if(s[i] == '!')
            continue;
        for(int j = i - 4; j >= 0 && s[j] == '!'; j-=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    for(int i = s.size()-5; i >= 0; i--){
        if(s[i] == '!')
            continue;
        for(int j = i + 4; j < s.size() && s[j] == '!'; j+=4){
            mapa[s[i]]++;
            s[j] = s[i];
        }
    }
    cout << mapa['R'] << " " << mapa['B'] << " " << mapa['Y'] << " " << mapa['G'] << endl;
}