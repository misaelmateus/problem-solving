//   Author : Misael Mateus 
//   Submission date: 2016-10-01 19:26:54
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> v;
    set<int>:: iterator it;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.insert(aux);
    }
    
    while(1){
        it = v.end();
        it--;
        int a = *it;
        int b = a;
        a = a/2;
        int flag = 1;
        while(a > 0){
            if(v.find(a) == v.end()){
                flag = 0;
                v.erase(b);
                v.insert(a);
                break;
            }
            else{
                a /= 2;
            }
        }
        
        if(flag)
            break;
    }
    
    
    it = v.begin();
    for( ; it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
       
}#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> v;
    set<int>:: iterator it;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.insert(aux);
    }
    
    while(1){
        it = v.end();
        it--;
        int a = *it;
        int b = a;
        a = a/2;
        int flag = 1;
        while(a > 0){
            if(v.find(a) == v.end()){
                flag = 0;
                v.erase(b);
                v.insert(a);
                break;
            }
            else{
                a /= 2;
            }
        }
        
        if(flag)
            break;
    }
    
    
    it = v.begin();
    for( ; it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
       
}#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> v;
    set<int>:: iterator it;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.insert(aux);
    }
    
    while(1){
        it = v.end();
        it--;
        int a = *it;
        int b = a;
        a = a/2;
        int flag = 1;
        while(a > 0){
            if(v.find(a) == v.end()){
                flag = 0;
                v.erase(b);
                v.insert(a);
                break;
            }
            else{
                a /= 2;
            }
        }
        
        if(flag)
            break;
    }
    
    
    it = v.begin();
    for( ; it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
       
}#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> v;
    set<int>:: iterator it;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.insert(aux);
    }
    
    while(1){
        it = v.end();
        it--;
        int a = *it;
        int b = a;
        a = a/2;
        int flag = 1;
        while(a > 0){
            if(v.find(a) == v.end()){
                flag = 0;
                v.erase(b);
                v.insert(a);
                break;
            }
            else{
                a /= 2;
            }
        }
        
        if(flag)
            break;
    }
    
    
    it = v.begin();
    for( ; it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
       
}