//   Author : Misael Mateus 
//   Submission date: 2017-01-23 03:12:20
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio( false );
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll i = 0LL, j = m+1LL;
    ll X, Y;
    X = (k - 1LL), Y = (n - k);
    
    while(j - i > 1LL){
        ll middle = (i+j)/2LL;
        
        ll y = min(Y, middle);
        ll x = min(X, middle);
        
        ll quant = ( (2LL*middle - y)*(y+1LL) + (2LL*middle - x - 1LL)*x)/2LL;
        //cout << middle << " " << quant << " " << x <<" " << y  << endl;
        if(quant <= m - n)
            i = middle;
        else
            j = middle;
    }
    
    cout << i + 1LL << endl;
    
    return 0;
}
    #include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio( false );
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll i = 0LL, j = m+1LL;
    ll X, Y;
    X = (k - 1LL), Y = (n - k);
    
    while(j - i > 1LL){
        ll middle = (i+j)/2LL;
        
        ll y = min(Y, middle);
        ll x = min(X, middle);
        
        ll quant = ( (2LL*middle - y)*(y+1LL) + (2LL*middle - x - 1LL)*x)/2LL;
        //cout << middle << " " << quant << " " << x <<" " << y  << endl;
        if(quant <= m - n)
            i = middle;
        else
            j = middle;
    }
    
    cout << i + 1LL << endl;
    
    return 0;
}
    #include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio( false );
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll i = 0LL, j = m+1LL;
    ll X, Y;
    X = (k - 1LL), Y = (n - k);
    
    while(j - i > 1LL){
        ll middle = (i+j)/2LL;
        
        ll y = min(Y, middle);
        ll x = min(X, middle);
        
        ll quant = ( (2LL*middle - y)*(y+1LL) + (2LL*middle - x - 1LL)*x)/2LL;
        //cout << middle << " " << quant << " " << x <<" " << y  << endl;
        if(quant <= m - n)
            i = middle;
        else
            j = middle;
    }
    
    cout << i + 1LL << endl;
    
    return 0;
}
    #include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio( false );
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll i = 0LL, j = m+1LL;
    ll X, Y;
    X = (k - 1LL), Y = (n - k);
    
    while(j - i > 1LL){
        ll middle = (i+j)/2LL;
        
        ll y = min(Y, middle);
        ll x = min(X, middle);
        
        ll quant = ( (2LL*middle - y)*(y+1LL) + (2LL*middle - x - 1LL)*x)/2LL;
        //cout << middle << " " << quant << " " << x <<" " << y  << endl;
        if(quant <= m - n)
            i = middle;
        else
            j = middle;
    }
    
    cout << i + 1LL << endl;
    
    return 0;
}
    