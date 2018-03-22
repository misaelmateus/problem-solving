#include <bits/stdc++.h>

using namespace std;

long calc_ans(long num){
    vector<long> primes;
    for(long i = 2; i*i <= num; i++){
        while(num % i == 0){
            primes.push_back(i);
            num /= i;
        }
    }
    if(num > 1) primes.push_back(num);
    long ans = 1;
    for(auto u : primes){
        ans = (ans) * u + 1;
    }
    return ans;
}
long longestSequence(vector <long> a) {
    long ans = 0;
    for(auto u : a)
        ans += calc_ans(u);
    return ans;
    //  Return the length of the longest possible sequence of moves.
}

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    long result = longestSequence(a);
    cout << result << endl;
    return 0;
}
