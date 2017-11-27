//   Author : Misael Mateus 
//   Submission date: 2016-11-19 00:37:12
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sum = (sum*2)/n;
    int i = 0;
    while(i < n){
        if(v[i] == -1){
            i++;
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(v[i] + v[j] == sum)
            {
                cout << i+1 << " " << j+1 << endl;
                v[i] = -1;
                v[j] = -1;
                break;
            }
        }
        i++;
    }
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sum = (sum*2)/n;
    int i = 0;
    while(i < n){
        if(v[i] == -1){
            i++;
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(v[i] + v[j] == sum)
            {
                cout << i+1 << " " << j+1 << endl;
                v[i] = -1;
                v[j] = -1;
                break;
            }
        }
        i++;
    }
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sum = (sum*2)/n;
    int i = 0;
    while(i < n){
        if(v[i] == -1){
            i++;
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(v[i] + v[j] == sum)
            {
                cout << i+1 << " " << j+1 << endl;
                v[i] = -1;
                v[j] = -1;
                break;
            }
        }
        i++;
    }
    return 0;
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    int n;
    cin >> n;
    int v[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sum = (sum*2)/n;
    int i = 0;
    while(i < n){
        if(v[i] == -1){
            i++;
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(v[i] + v[j] == sum)
            {
                cout << i+1 << " " << j+1 << endl;
                v[i] = -1;
                v[j] = -1;
                break;
            }
        }
        i++;
    }
    return 0;
}