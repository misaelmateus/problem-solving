//   Author : Misael Mateus 
//   Submission date: 2016-11-22 16:15:46
#include<bits/stdc++.h>
#define MAXC 200010
using namespace std;
int m[MAXC], v[MAXC];
int main(){
    ios::sync_with_stdio( false );
    int c, n;
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        m[coin]++;
    }
    
    for(int i = 1; i <= c; i++){
        if(m[i] > 0)
            v[i] = i;
        else
            v[i] = v[i-1];
    }
    
    for(int x = 1; x <= c; x++){
        int s = c;
        int ult = s;
        int flag = 0;
        //cout << endl;
        while(s > 0){
            
            int i = v[ult];
            if(x <= s && x >= i && !flag){
                s -= x;
                ult = x;
                flag = 1;
                continue;
            }
            if(i == 0)
            {
                cout << x << endl;
                return 0;
            }
            //cout << i << endl;
            s -= i*min(s/i, m[i]);
            ult = min(i-1, s);
        }
    }
    
    cout << "Greed is good" << endl;
    return 0;
}#include<bits/stdc++.h>
#define MAXC 200010
using namespace std;
int m[MAXC], v[MAXC];
int main(){
    ios::sync_with_stdio( false );
    int c, n;
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        m[coin]++;
    }
    
    for(int i = 1; i <= c; i++){
        if(m[i] > 0)
            v[i] = i;
        else
            v[i] = v[i-1];
    }
    
    for(int x = 1; x <= c; x++){
        int s = c;
        int ult = s;
        int flag = 0;
        //cout << endl;
        while(s > 0){
            
            int i = v[ult];
            if(x <= s && x >= i && !flag){
                s -= x;
                ult = x;
                flag = 1;
                continue;
            }
            if(i == 0)
            {
                cout << x << endl;
                return 0;
            }
            //cout << i << endl;
            s -= i*min(s/i, m[i]);
            ult = min(i-1, s);
        }
    }
    
    cout << "Greed is good" << endl;
    return 0;
}#include<bits/stdc++.h>
#define MAXC 200010
using namespace std;
int m[MAXC], v[MAXC];
int main(){
    ios::sync_with_stdio( false );
    int c, n;
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        m[coin]++;
    }
    
    for(int i = 1; i <= c; i++){
        if(m[i] > 0)
            v[i] = i;
        else
            v[i] = v[i-1];
    }
    
    for(int x = 1; x <= c; x++){
        int s = c;
        int ult = s;
        int flag = 0;
        //cout << endl;
        while(s > 0){
            
            int i = v[ult];
            if(x <= s && x >= i && !flag){
                s -= x;
                ult = x;
                flag = 1;
                continue;
            }
            if(i == 0)
            {
                cout << x << endl;
                return 0;
            }
            //cout << i << endl;
            s -= i*min(s/i, m[i]);
            ult = min(i-1, s);
        }
    }
    
    cout << "Greed is good" << endl;
    return 0;
}#include<bits/stdc++.h>
#define MAXC 200010
using namespace std;
int m[MAXC], v[MAXC];
int main(){
    ios::sync_with_stdio( false );
    int c, n;
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        m[coin]++;
    }
    
    for(int i = 1; i <= c; i++){
        if(m[i] > 0)
            v[i] = i;
        else
            v[i] = v[i-1];
    }
    
    for(int x = 1; x <= c; x++){
        int s = c;
        int ult = s;
        int flag = 0;
        //cout << endl;
        while(s > 0){
            
            int i = v[ult];
            if(x <= s && x >= i && !flag){
                s -= x;
                ult = x;
                flag = 1;
                continue;
            }
            if(i == 0)
            {
                cout << x << endl;
                return 0;
            }
            //cout << i << endl;
            s -= i*min(s/i, m[i]);
            ult = min(i-1, s);
        }
    }
    
    cout << "Greed is good" << endl;
    return 0;
}