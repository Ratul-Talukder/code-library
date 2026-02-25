// https://cses.fi/problemset/task/1679
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  //getting node's indegree
  vector<int> indegree(n+1,0);
  for (int i = 1; i <= n; ++i) {
    for (int &x : g[i]) indegree[x]++;
  }

  //getting the start points
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == 0) q.push(i);
  }

  //getting the order using BFS aka Kahn's algo
  vector<int> ord;

  while (!q.empty()) {
    int f = q.front();
    q.pop();
    ord.push_back(f);

    for (int &x : g[f]) {
        indegree[x]--;

        if (indegree[x] == 0) q.push(x);
    }
  }
  
  bool isFeasible = true;

  //check whether a cycle exists
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] != 0) { //there is cycle
        isFeasible = false;
        break;
    }
  }
  

  if (isFeasible) {
    for (auto &x : ord) cout << x << " ";
  }
  else cout << "IMPOSSIBLE";

  return 0;
}
