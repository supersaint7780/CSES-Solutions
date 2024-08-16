#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)
#define LONG_INF (ll) 1e18
#define INF (ll) 1e9 
#define rall(x) rbegin(x), rend(x)

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    private:
    int size;
    vector<ll> tree;

    void build(vector<ll> &arr, int v, int tl, int tr) {
        if(tl == tr) {
            tree[v] = arr[tl];
        } else {
            int mid = (tr - tl)/2 + tl;
            build(arr, 2 * v, tl, mid);
            build(arr, 2 * v + 1, mid + 1, tr);
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        }
    }

    ll query(int v, int tl, int tr, int ql, int qr) {
        if(ql > tr || qr < tl) {
            return INF;
        }
        if(ql == tl && qr == tr) {
            return tree[v];
        }
        int mid = (tr - tl)/2 + tl;
        return min(
            query(v * 2, tl, mid, ql, min(qr, mid)),
            query(v * 2 + 1, mid + 1, tr, max(ql, mid + 1), qr)
        );
    }

    void update(int v, int tl, int tr, int point, int val) {
        if(tl == tr) {
            tree[v] = val;
        } else {
            int mid = (tr - tl)/2 + tl;
            if(point <= mid) {
                update(v * 2, tl, mid, point, val);
            } else {
                update(v * 2 + 1, mid + 1, tr, point, val);
            }
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    public:
    SegmentTree(vector<ll> &arr): size(arr.size()), tree(arr.size() * 4) {
        build(arr, 1, 0, arr.size() - 1);
    }

    ll query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }

    void update(int idx, ll val) {
        update(1, 0, size - 1, idx, val);
    }
};


void solve() {
    int size = 0, queries = 0;
    cin >> size >> queries;

    vll arr(size);
    for(auto &it: arr) cin >> it;

    SegmentTree minTree(arr);
    while(queries--) {
        int type = 0;
        cin >> type;
        if(type == 1) {
            int idx = 0, val = 0;
            cin >> idx >> val;
            --idx;
            minTree.update(idx, val);
        } else {
            int l = 0, r = 0;
            cin >> l >> r;
            --l;
            --r;
            cout << minTree.query(l, r) << endl;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int testcases = 1;
    // cin >> testcases;
    while(testcases--) {
        solve();
    }
    return 0;
}