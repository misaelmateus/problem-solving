#include <bits/stdc++.h>

using namespace std;

long sumOfGroup(int k) {
    long a = ((long)(k)*(long)(k-1)/2 + 1)*2 - 1;
    long sum = 0LL;
    for(int i = 0; i < k; i++){
        sum += a;
        a += 2;
    }
    return sum;
}

int main() {
    int k;
    cin >> k;
    long answer = sumOfGroup(k);
    cout << answer << endl;
    return 0;
}
