#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n), b(m);
    double f = sqrt(2.0);
    for(int i = 0; i < n; i++)
        cin >> a[i].first;
    for(int i = 0; i < n; i++)
        cin >> a[i].second;
    
    for(int i = 0; i < m; i++)
        cin >> b[i].first;
    for(int i = 0; i < m; i++)
        cin >> b[i].second;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        while(a[i].second && j < m){
            if(a[i].first < b[j].first*f && b[j].second){
                int q_now = min(a[i].second, b[j].second);
                a[i].second -= q_now;
                b[j].second -= q_now;
                tot += q_now;
            }
            else j++;
        }
    }
    cout << tot << "\n";
    return 0;
}
