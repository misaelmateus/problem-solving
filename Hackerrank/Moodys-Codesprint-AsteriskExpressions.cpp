#include<bits/stdc++.h>
#define ll long long
#define L 1000000007LL
using namespace std;

ll pot(ll a, ll b){
    if(b == 0)
        return 1LL;
    if(b == 1LL)
        return a%L;
    ll m = pot(a, b >> 1);
    m = (m*m)%L;
    if(b%2LL == 1)
        m = (m*a)%L;
    return m;
}


int main(){
    int t;
    cin >> t;
    for(int l = 0; l < t; l++){
        string s;
        cin >> s;
        vector<ll> v;
        vector<ll> op;
        if(s[0] == '*' || s[s.size()-1] == '*'){
            cout << "Syntax Error" << endl;
            continue;
        }
        int flag = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*')
            {
                if(i + 1 < s.size() && s[i+1] == '*' ){
                    if(i + 2 < s.size() && s[i+2] == '*')
                    {
                        cout << "Syntax Error" << endl;
                        flag = 0;
                        break;
                    }
                    op.push_back(1);
                    i++;
                }
                else
                    op.push_back(0);
            }
            else{
                ll num = 0LL, j, aux = 1LL;
                for(j = i; j < s.size() && s[j] != '*'; j++);
                j--;
                
                for(int k = j; k >= i; k--){
                    num += (ll)(s[k] - '0')*aux;
                    aux*= 10LL;
                }
                i = j;
                v.push_back(num);
            }
        }
        if(!flag)
            continue;
        
        ll resp = 1LL;
        
        for(int i = 0; i < v.size(); i++)
        {
            if( i >= op.size() || op[i] == 0)
                resp = (resp * (v[i] % L) ) % L;
            else{
                while(i < op.size() && op[i] == 1){
                    ll num = pot((v[i]%L), v[i+1]);
                    v[i+1] = num;
                    i++;
                    
                }
                resp = (resp * (v[i] % L) ) % L;
            }
        }
        
        
        cout << resp << endl;
    }
    
}