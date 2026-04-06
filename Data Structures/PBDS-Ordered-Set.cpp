#include<bits/stdc++.h>
using namespace std;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> 
using o_set = tree<
    T, 
    null_type, 
    less<T>, 
    rb_tree_tag,
    tree_order_statistics_node_update
>;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    o_set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(7);

    /*
    Count elements < x
    s.order_of_key(x)
    Output = number of elements strictly less than x
    */
    /*
    Find k-th smallest element (0-based)
    cout << *s.find_by_order(0); // smallest
    cout << *s.find_by_order(1); // 2nd smallest
    */

    return 0;
}