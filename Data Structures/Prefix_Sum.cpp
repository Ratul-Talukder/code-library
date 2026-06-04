#include <bits/stdc++.h>
using namespace std;

// 1D Prefix
const int N = 1e5 + 5;
int a[N];
long long pref[N];
void build_prefix(int n)
{
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }
}
long long range_sum(int l, int r)
{
    return pref[r] - pref[l - 1];
}

// 2D Prefix
const int N = 1005;
int a[N][N];
long long pref[N][N];
void build_prefix(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
}
/*
Sum of rectangle:
(x1, y1) → top-left
(x2, y2) → bottom-right
*/
long long range_sum(int x1, int y1, int x2, int y2)
{
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build_prefix(n);
    int l, r;
    cin >> l >> r;
    cout << range_sum(l, r); // 1based indx
    build_prefix(n, m);
    cout << range_sum(x1, y1, x2, y2);

    return 0;
}