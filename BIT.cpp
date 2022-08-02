#define N 100001
using ll = long long;

struct BIT {
    ll tree[N];
    void add(int index, ll value) {
        while (index < N) {
            tree[index] += value;
            index += index & -index;
        }
    }
    ll prefixSum(int index) {
        ll sum = 0;
        while (index) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
    ll rangeSum(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }
} bit;
