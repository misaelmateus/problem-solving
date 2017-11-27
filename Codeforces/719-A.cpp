//   Author : Misael Mateus 
//   Submission date: 2016-09-23 19:22:46
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    if(n <= 1 && v[0] != 0 && v[0] != 15){
        cout << -1 << endl;
        return 0;
    }
    if(n == 1){
        if(v[0] == 0)
            cout << "UP" << endl;
        else
            cout << "DOWN" << endl;
        return 0;
    }
    if( (v[n-2] == 1 && v[n-1] == 0 )|| (v[n-2] < v[n-1] && v[n-2] != 14 ) ){
        cout << "UP" << endl;
        return 0;
    } 
    
    cout << "DOWN" << endl;
    
    return 0;
}#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    if(n <= 1 && v[0] != 0 && v[0] != 15){
        cout << -1 << endl;
        return 0;
    }
    if(n == 1){
        if(v[0] == 0)
            cout << "UP" << endl;
        else
            cout << "DOWN" << endl;
        return 0;
    }
    if( (v[n-2] == 1 && v[n-1] == 0 )|| (v[n-2] < v[n-1] && v[n-2] != 14 ) ){
        cout << "UP" << endl;
        return 0;
    } 
    
    cout << "DOWN" << endl;
    
    return 0;
}#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    if(n <= 1 && v[0] != 0 && v[0] != 15){
        cout << -1 << endl;
        return 0;
    }
    if(n == 1){
        if(v[0] == 0)
            cout << "UP" << endl;
        else
            cout << "DOWN" << endl;
        return 0;
    }
    if( (v[n-2] == 1 && v[n-1] == 0 )|| (v[n-2] < v[n-1] && v[n-2] != 14 ) ){
        cout << "UP" << endl;
        return 0;
    } 
    
    cout << "DOWN" << endl;
    
    return 0;
}#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    if(n <= 1 && v[0] != 0 && v[0] != 15){
        cout << -1 << endl;
        return 0;
    }
    if(n == 1){
        if(v[0] == 0)
            cout << "UP" << endl;
        else
            cout << "DOWN" << endl;
        return 0;
    }
    if( (v[n-2] == 1 && v[n-1] == 0 )|| (v[n-2] < v[n-1] && v[n-2] != 14 ) ){
        cout << "UP" << endl;
        return 0;
    } 
    
    cout << "DOWN" << endl;
    
    return 0;
}