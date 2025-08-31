#include<bits/stdc++.h>
using namespace std;

//O(n)
void divisors_naive(int n) {

    for (int i = 1; i <= n; ++i) {

        if (n % i == 0) cout << i << " ";
    }
}

//O(sqrt(n))
void divisors_optimal(int n) {

    for (int i = 1; i*i <= n; ++i) {

        if (n % i == 0) cout << i << " ";
        if (i != n/i) cout << n/i << " ";
    }
}

bool isPrime(int n) {

    for (int i = 2; i*i <= n; ++i) {

        if (n % i == 0) return false;
    }
    return true;
}

void soln() {
    
    int n; cin >> n;
    divisors_naive(n); //O(n)
    divisors_optimal(n); //O(sqrt(n))
    cout << isPrime(n);

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;  cin >> testCase;
    while(testCase--)soln();
    return 0;
}
