#define N 100001

struct union_set {
    int parent[N];
    int findParent(int x) {
        return x == parent[x] ? x : parent[x] = findParent(parent[x]);
    }
    void join(int x, int y) { parent[findParent(x)] = findParent(y); }
};
