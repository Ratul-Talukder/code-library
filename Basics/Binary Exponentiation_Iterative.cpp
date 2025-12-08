#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int power(int a, int b) { // O(log n)

    int ans = 1 % M;

    while (b > 0){

        if(b & 1){
            ans = (1LL * ans * a) % M;
        }
        a = (1LL *a * a) % M;
        b >>= 1;
    }
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << power(2, 1000000000) << '\n';
  return 0;
}
