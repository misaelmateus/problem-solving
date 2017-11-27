//   Author : Misael Mateus 
//   Submission date: 2016-09-30 19:39:42
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    vector<int> resp;
    int cont = 0;
    for(int i = 0; i <= s.size(); i++){
        if(i == s.size() || s[i] == 'W'){
            if(!flag)
                continue;
            flag = 0;
            resp.push_back(cont);
            cont = 0;
        }
        else if(s[i] == 'B'){
            flag = 1;
            cont++;
        }
    }
    
    cout << resp.size() << endl;
    for(int i = 0; i < resp.size(); i++)
        cout << resp[i] << " ";
    cout << endl;
    
    return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    vector<int> resp;
    int cont = 0;
    for(int i = 0; i <= s.size(); i++){
        if(i == s.size() || s[i] == 'W'){
            if(!flag)
                continue;
            flag = 0;
            resp.push_back(cont);
            cont = 0;
        }
        else if(s[i] == 'B'){
            flag = 1;
            cont++;
        }
    }
    
    cout << resp.size() << endl;
    for(int i = 0; i < resp.size(); i++)
        cout << resp[i] << " ";
    cout << endl;
    
    return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    vector<int> resp;
    int cont = 0;
    for(int i = 0; i <= s.size(); i++){
        if(i == s.size() || s[i] == 'W'){
            if(!flag)
                continue;
            flag = 0;
            resp.push_back(cont);
            cont = 0;
        }
        else if(s[i] == 'B'){
            flag = 1;
            cont++;
        }
    }
    
    cout << resp.size() << endl;
    for(int i = 0; i < resp.size(); i++)
        cout << resp[i] << " ";
    cout << endl;
    
    return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    vector<int> resp;
    int cont = 0;
    for(int i = 0; i <= s.size(); i++){
        if(i == s.size() || s[i] == 'W'){
            if(!flag)
                continue;
            flag = 0;
            resp.push_back(cont);
            cont = 0;
        }
        else if(s[i] == 'B'){
            flag = 1;
            cont++;
        }
    }
    
    cout << resp.size() << endl;
    for(int i = 0; i < resp.size(); i++)
        cout << resp[i] << " ";
    cout << endl;
    
    return 0;
}