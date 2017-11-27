//   Author : Misael Mateus 
//   Submission date: 2017-11-01 20:37:31
#include<bits/stdc++.h>
using namespace std;
map<char, int> mapa;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v1;
    vector<char> p;
    for(int i = 0; i < n; i++)
        mapa[s[i]]++;
    for(auto u: mapa){
        if(u.second % 2) v1.push_back(u.first);
        int x = u.second;
        while(x >= 2)
            p.push_back(u.first), x-= 2;
    }
    int a = v1.size();
    if(a == 0){
        string aux = "", aux1;
        for(int j = 0; j < p.size(); j++){
            aux += p[j];
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += aux1;
        cout << "1\n";
        cout << aux << " ";
        return 0;
    }
    int b = p.size();
    int x = 0;
    for(; x < b; x++){
        if((b - x) % (a + 2*x) == 0)
            break;
    }
    while(x--){
        v1.push_back(p.back());
        v1.push_back(p.back());
        p.pop_back();
    }
    int i = 0;
    int q = p.size()/v1.size();
    cout << v1.size() << "\n";
    for(; i < v1.size(); i++){
        string aux = "", aux1;
        for(int j = 0; j < q; j++){
            aux += p.back();
            p.pop_back();
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += v1[i];
        aux += aux1;
        cout << aux << " ";
    }
    cout << "\n";
}
#include<bits/stdc++.h>
using namespace std;
map<char, int> mapa;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v1;
    vector<char> p;
    for(int i = 0; i < n; i++)
        mapa[s[i]]++;
    for(auto u: mapa){
        if(u.second % 2) v1.push_back(u.first);
        int x = u.second;
        while(x >= 2)
            p.push_back(u.first), x-= 2;
    }
    int a = v1.size();
    if(a == 0){
        string aux = "", aux1;
        for(int j = 0; j < p.size(); j++){
            aux += p[j];
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += aux1;
        cout << "1\n";
        cout << aux << " ";
        return 0;
    }
    int b = p.size();
    int x = 0;
    for(; x < b; x++){
        if((b - x) % (a + 2*x) == 0)
            break;
    }
    while(x--){
        v1.push_back(p.back());
        v1.push_back(p.back());
        p.pop_back();
    }
    int i = 0;
    int q = p.size()/v1.size();
    cout << v1.size() << "\n";
    for(; i < v1.size(); i++){
        string aux = "", aux1;
        for(int j = 0; j < q; j++){
            aux += p.back();
            p.pop_back();
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += v1[i];
        aux += aux1;
        cout << aux << " ";
    }
    cout << "\n";
}
#include<bits/stdc++.h>
using namespace std;
map<char, int> mapa;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v1;
    vector<char> p;
    for(int i = 0; i < n; i++)
        mapa[s[i]]++;
    for(auto u: mapa){
        if(u.second % 2) v1.push_back(u.first);
        int x = u.second;
        while(x >= 2)
            p.push_back(u.first), x-= 2;
    }
    int a = v1.size();
    if(a == 0){
        string aux = "", aux1;
        for(int j = 0; j < p.size(); j++){
            aux += p[j];
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += aux1;
        cout << "1\n";
        cout << aux << " ";
        return 0;
    }
    int b = p.size();
    int x = 0;
    for(; x < b; x++){
        if((b - x) % (a + 2*x) == 0)
            break;
    }
    while(x--){
        v1.push_back(p.back());
        v1.push_back(p.back());
        p.pop_back();
    }
    int i = 0;
    int q = p.size()/v1.size();
    cout << v1.size() << "\n";
    for(; i < v1.size(); i++){
        string aux = "", aux1;
        for(int j = 0; j < q; j++){
            aux += p.back();
            p.pop_back();
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += v1[i];
        aux += aux1;
        cout << aux << " ";
    }
    cout << "\n";
}
#include<bits/stdc++.h>
using namespace std;
map<char, int> mapa;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v1;
    vector<char> p;
    for(int i = 0; i < n; i++)
        mapa[s[i]]++;
    for(auto u: mapa){
        if(u.second % 2) v1.push_back(u.first);
        int x = u.second;
        while(x >= 2)
            p.push_back(u.first), x-= 2;
    }
    int a = v1.size();
    if(a == 0){
        string aux = "", aux1;
        for(int j = 0; j < p.size(); j++){
            aux += p[j];
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += aux1;
        cout << "1\n";
        cout << aux << " ";
        return 0;
    }
    int b = p.size();
    int x = 0;
    for(; x < b; x++){
        if((b - x) % (a + 2*x) == 0)
            break;
    }
    while(x--){
        v1.push_back(p.back());
        v1.push_back(p.back());
        p.pop_back();
    }
    int i = 0;
    int q = p.size()/v1.size();
    cout << v1.size() << "\n";
    for(; i < v1.size(); i++){
        string aux = "", aux1;
        for(int j = 0; j < q; j++){
            aux += p.back();
            p.pop_back();
        }
        aux1 = aux;
        reverse(aux1.begin(), aux1.end());
        aux += v1[i];
        aux += aux1;
        cout << aux << " ";
    }
    cout << "\n";
}
