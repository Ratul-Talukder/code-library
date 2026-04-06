#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// ---------------- ORDERED SET ----------------
// Supports:
// order_of_key(x) -> number of elements strictly smaller than x
// find_by_order(k) -> k-th smallest element (0-indexed)

template <typename T>
using o_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

// ---------------- ORDERED MAP ----------------
// Key-value structure with ordering on key

template <typename T, typename R>
using o_map = tree<
    T,
    R,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    o_set<int> s;

    s.insert(10);
    s.insert(5);
    s.insert(20);

    cout << s.order_of_key(15);  // 2 (5,10)
    cout << *s.find_by_order(1); // 10

    o_map<int, int> mp;

    mp[10] = 100;
    mp[20] = 200;
    mp[50] = 500;

    cout << mp.order_of_key(50); // 2 → (10, 20)
    auto it = mp.find_by_order(1);
    cout << it->first; // 20

    return 0;
}