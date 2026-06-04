#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(100100);
vector<int> vis(100100, 0);
vector<int> topo;
bool isCycle = false;

void DFS(int node)
{
    vis[node] = 1;

    for (auto v : g[node])
    {
        if (vis[v] == 0)
        {
            DFS(v);
        }
        else if (vis[v] == 1)
        {
            isCycle = true;
            return;
        }
    }
    vis[node] = 2;
    topo.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == 0)
        {
            DFS(i);
        }
        if (isCycle)
            break;
    }

    if (isCycle)
        cout << "IMPOSSIBLE";
    else
    {
        reverse(topo.begin(), topo.end());
        for (auto e : topo)
            cout << e << " ";
    }

    return 0;
}

// https://cses.fi/problemset/result/17407663/