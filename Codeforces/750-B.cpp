//   Author : Misael Mateus 
//   Submission date: 2017-01-06 02:09:55
#include<bits/stdc++.h>
using namespace std;

int mod(int n, int base){
    n %= base;
    while(n < 0)
        n += base;
    return n;
}
int main(){
    int n;
    cin >> n;
    int a;
    string s;
    
    int h = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(s[0] == 'S')
            h += a;
        else if(s[0] == 'N')
            h -= a;
        else if(mod(h, 20000) == 0){
            cout << "NO" << endl;
            return 0;
        }
        if(h < 0 || h > 20000){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if(h != 0) 
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

    return 0;
}#include<bits/stdc++.h>
using namespace std;

int mod(int n, int base){
    n %= base;
    while(n < 0)
        n += base;
    return n;
}
int main(){
    int n;
    cin >> n;
    int a;
    string s;
    
    int h = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(s[0] == 'S')
            h += a;
        else if(s[0] == 'N')
            h -= a;
        else if(mod(h, 20000) == 0){
            cout << "NO" << endl;
            return 0;
        }
        if(h < 0 || h > 20000){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if(h != 0) 
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

    return 0;
}#include<bits/stdc++.h>
using namespace std;

int mod(int n, int base){
    n %= base;
    while(n < 0)
        n += base;
    return n;
}
int main(){
    int n;
    cin >> n;
    int a;
    string s;
    
    int h = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(s[0] == 'S')
            h += a;
        else if(s[0] == 'N')
            h -= a;
        else if(mod(h, 20000) == 0){
            cout << "NO" << endl;
            return 0;
        }
        if(h < 0 || h > 20000){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if(h != 0) 
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

    return 0;
}#include<bits/stdc++.h>
using namespace std;

int mod(int n, int base){
    n %= base;
    while(n < 0)
        n += base;
    return n;
}
int main(){
    int n;
    cin >> n;
    int a;
    string s;
    
    int h = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(s[0] == 'S')
            h += a;
        else if(s[0] == 'N')
            h -= a;
        else if(mod(h, 20000) == 0){
            cout << "NO" << endl;
            return 0;
        }
        if(h < 0 || h > 20000){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if(h != 0) 
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

    return 0;
}