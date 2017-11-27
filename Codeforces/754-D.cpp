//   Author : Misael Mateus 
//   Submission date: 2017-01-06 21:39:46
#include<bits/stdc++.h>
using namespace std;
bool ord(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.second.first < b.second.first;
}

bool ord1(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.second.second > b.second.second;
}
int main(){
    int n, k;
    cin >> n >> k;
    pair<int, pair<int, int> > p[n];
    
    int a, b;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        p[i] = {i+1, {a, b}};
    }
    
    sort(p, p+n, ord);
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 0; i < k-1; i++){
        pq.push(p[i].second.second);
    }
    
    int best = k-1, ma = 0;
    for(int i = k-1; i < n; i++){
        pq.push(p[i].second.second);
        int dist = pq.top() - p[i].second.first + 1;
        
        if(dist > ma)
            best = i, ma = dist;
        pq.pop();
    }
    
    cout << ma << endl;
    
    vector<int> resp;
    resp.push_back(p[best].first);
    sort(p, p+best, ord1);
    
    for(int i = 0; i < k-1; i++)
        resp.push_back(p[i].first);
        
    sort(resp.begin(), resp.end());
    for(int i = 0; i < k; i++)
        cout << resp[i] << " ";
}