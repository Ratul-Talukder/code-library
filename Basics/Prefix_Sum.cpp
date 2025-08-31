#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
long long prefix_sum[N];
int a[N];

void soln() {
    
    int n, q; cin >> n >> q;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l-1] << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;  //cin >> testCase;
    while(testCase--)soln();
    return 0;
}

// https://cses.fi/problemset/task/1646/