//   Author : Misael Mateus 
//   Submission date: 2016-09-30 21:27:26
#include<bits/stdc++.h>
#define ll long long
#define ii pair<long long, int>
using namespace std;
int main(){
    int n, k, x;
    int plus = 0, menos = 0;
    int zero = 0;
    cin >> n >> k >> x;
    priority_queue<ii> neg;
    priority_queue<ii, vector<ii>, greater<ii> > pos;
    queue<int> z;
    ll v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 0)
            zero++, z.push(i);
        if(v[i] > 0){
            pos.push({v[i], i});
            plus++;
        }
        if(v[i] < 0){
            neg.push({v[i], i});
            menos++;
        }
    }
    
    while(k--){
        
        if(zero > 0){
            int a = z.front();
            z.pop();
            while(v[a] != 0){
                a = z.front();
                z.pop();
            }
            if(menos % 2 == 0){
                v[a] -= x;
                menos++;
                neg.push({v[a], a});
                zero--;
            }
            else
            {
                v[a] += x;
                pos.push({v[a] , a});
                plus++;
                zero--;
            }
        }
        else{
            int a, b;
            a = -1;
            ll d;
            while(!pos.empty() && ( a == -1 || v[a] != d) ){
                a = pos.top().second;
                d = pos.top().first;
                if(v[a] != d)
                    pos.pop();
            }
            if(a != -1 && v[a] != d)
                a = -1;
            b = -1;
            while(!neg.empty() && ( b == -1 || v[b] != d) ){
                b = neg.top().second;
                d = neg.top().first;
                if(v[b] != d)
                    neg.pop();
            }
            if(b != -1 && v[b] != d)
                b = -1;
            //cout << a << " " << b << endl;
            if(a == -1 && b == -1)
                continue;
            if(a != -1 && (b == -1 || v[a] < -v[b]) ){
                pos.pop();
                if(menos%2 == 0){
                    v[a] -= x;
                    plus--;
                    if(v[a] == 0)
                        zero++, z.push(a);
                    if(v[a] < 0)
                        menos++, neg.push({v[a], a});
                    if(v[a] > 0){
                        plus++;
                        pos.push({v[a], a});
                    }
                }
                else{
                    v[a] += x;
                    pos.push({v[a], a});
                }
            }
            else{
                neg.pop();
                if(menos%2 == 0){
                    v[b] += x;
                    menos--;
                    if(v[b] == 0)
                        zero++, z.push(b);
                    if(v[b] < 0)
                        menos++, neg.push({v[b], b});
                    if(v[b] > 0){
                        plus++;
                        pos.push({v[b], b});
                    }
                }
                else{
                    v[b] -= x;
                    neg.push({v[b], b});
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}