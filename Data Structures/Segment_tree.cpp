#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree
{
private:
    vector<ll> tree; // segment tree array
    vector<ll> arr;  // given array
    int n;           // array size

    void build(int idx, int b, int e)
    {

        // Base Case: it's a leaf node (b == e)
        if (b == e)
        {
            tree[idx] = arr[b];
            return;
        }

        // If it's not a leaf, it has two children
        int mid = (b + e) / 2;
        int l = 2 * idx + 1; // leftChild index (0 based)
        int r = 2 * idx + 2; // rightChild index

        build(l, b, mid);     // build leftChild
        build(r, mid + 1, e); // build rightChild

        // After building children, update the current node's value according to the problem
        tree[idx] = tree[l] + tree[r];
        // tree[idx] = min(tree[l],tree[r]);
        // tree[idx] = max(tree[l],tree[r]);
    }

    ll query(int idx, int b, int e, int ql, int qr)
    {

        // Case 1: No overlap
        if (b > qr || e < ql)
        {
            return 0; // identity for sum
            // return LLONG_MAX; //identity for min
            // return LLONG_MIN; //identity for max
        }

        // Case 2: Complete Overlap
        if (b >= ql && e <= qr)
            return tree[idx];

        // Case 3: Partial Overlap -> ask the children and combine
        int mid = (b + e) / 2;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;

        ll left_res = query(l, b, mid, ql, qr);
        ll right_res = query(r, mid + 1, r, ql, qr);

        return left_res + right_res;
        // return min(left_res,right_res);
        // return max(left_res,right_res);
    }

    void update(int idx, int b, int e, int pos, int val)
    {
        // Base Case: found the leaf node to update
        if (b == e)
        {
            arr[b] = val;    // update the original array (optional but good practice)
            tree[idx] = val; // update the segment tree
            return;
        }

        int mid = (b + e) / 2;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;

        // Decide which child the `pos` belongs to
        if (pos <= mid)
        {
            // Go to the left child
            update(l, b, mid, pos, val);
        }
        else
        {
            // Go to the right child
            update(r, mid + 1, e, pos, val);
        }

        // After updating a child, update the current node's value
        tree[idx] = tree[l] + tree[r];
        // tree[idx] = min(tree[l],tree[r]);
        // tree[idx] = max(tree[l],tree[r]);
    }

public:
    SegmentTree(vector<ll> &input)
    {
        arr = input;
        n == arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    ll getQuery(int ql, int qr)
    {
        return query(0, 0, n - 1, ql, qr);
    }
    void updValue(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &x : a)
        cin >> x;

    SegmentTree st(arr);

    for (int i = 1; i <= m; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int pos, val;
            cin >> pos >> val;
            st.updValue(pos, val);
        }
        else
        {
            int ql, qr;
            cin >> ql >> qr;

            ll ans = st.getQuery(ql, qr);
            cout << ans << '\n';
        }
    }
    return 0;
}