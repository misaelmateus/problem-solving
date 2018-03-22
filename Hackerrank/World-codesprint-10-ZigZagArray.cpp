#include <bits/stdc++.h>

using namespace std;

int minimumDeletions(vector < int > a){
    int cont = 0;
    for(int i = 0; i + 2 < a.size(); i++){
        if((a[i+1] >= a[i] && a[i+2] >= a[i+1]) || (a[i+1] <= a[i] && a[i+2] <= a[i+1]))
            cont++;
    }
    return cont;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    // Return the minimum number of elements to delete to make the array zigzag
    int result = minimumDeletions(a);
    cout << result << endl;
    return 0;
}
