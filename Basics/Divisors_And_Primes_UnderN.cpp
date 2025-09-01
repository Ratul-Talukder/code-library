#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

int divisors[N];

void soln() {
    
    int n; cin >> n;

    //O(nlog(n))
    for (int i = 1; i <= n; ++i) {

        for (int j = i; j <= n; j+=i) divisors[j]++; //log(n)
    }

    for (int i = 1; i <= n; ++i) cout << divisors[i] << " ";

    cout << '\n';

    //Prime Numbers Under n
    for (int i = 1; i <= n; ++i) {

        if (divisors[i] == 2) cout << i << " ";
    }



}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;  //cin >> testCase;
    while(testCase--)soln();
    return 0;
}