#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int power(int a, int b) { // O(log n)

    if (b == 1) return a;

    int res = power(a, b/2);

    if (b & 1) return ((1LL * res * res % M) * a) % M;
    else return (1LL * res * res) % M;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << power(2, 1000000000) << '\n';
  return 0;
}
