#define N 100001
using ll = long long;

int origin[N];

struct seg_tree {
    ll tree[N << 2];

    void build(int node, int L, int R) {
        if (L == R) {
            tree[node] = origin[L];
        } else {
            int mid = (L + R) >> 1;
            build(node * 2 + 1, L, mid);
            build(node * 2 + 2, mid + 1, R);
            tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
        }
    }

    void update(int node, int L, int R, int index, int value) {
        if (L == R) {
            tree[node] = value;
            return;
        }
        int mid = (L + R) >> 1;
        if (mid >= index) {
            update(node * 2 + 1, L, mid, index, value);
        } else {
            update(node * 2 + 2, mid + 1, R, index, value);
        }
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    int query(int node, int L, int R, int l, int r) {
        if (l <= L && R <= r) {
            return tree[node];
        }
        if (l > R || r < L) {
            return 0;
        }
        int mid = (L + R) >> 1;
        return query(node * 2 + 1, L, mid, l, r) +
               query(node * 2 + 2, mid + 1, R, l, r);
    }
};
