#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define MAXN 1000010
#define ll long long
/* This function calculates (a^b) % MOD */
int64 fastPow(int64 a, int64 b)
{
    int64 res = 1LL;
    while (b > 0LL)
    {
        if (b & 1LL)
        {
            res *= a; res %= MOD;
        }
        a *= a; a %= MOD;
        b >>= 1;
    }
    return res;
}
 
/*
    Modular Multiplicative Inverse
    Using Euler's Theorem
*/
 
long long InverseEuler(int64 n)
{
    return fastPow(n, MOD-2LL);
}

ll fat[MAXN], inv_fat[MAXN];

int cont[30];
int main(){
    fat[0] = 1;
    inv_fat[0] = inv_fat[1] = 1;
    for(int i = 1; i < MAXN; i++)
        fat[i] = (fat[i-1]*i) % MOD;
    for(int i = 2; i < MAXN; i++)
        inv_fat[i] = (inv_fat[i-1]*InverseEuler(i)) % MOD;

    string a, b;
    cin >> a >> b;

    int n = a.size();
    ll ans = 0LL;
    ll num = num1 = fat[n];
    for(int i = 0; i < n; i++)
        cont[a[i] - 'a']++;

    for(int i = 0; i < 26; i++) num = (num * inv_fat[cont[i]]) % MOD;
    int l = 0;
    for(; l < n; l++){
        if(a[i] == b[i]) cont[a[i] - 'a']--;
        else break;
    }
    for(int i = l; i < n; i++){
        for(int j = a[i] - '0' +1; j < 26; j++){
            ans = (ans + ((num*fat[cont[j]])%P)*inv_fat[cont[j]-1]) % P;
        }
        num = (num*fat[cont[a[i] - '0']]) % P;
    }

}