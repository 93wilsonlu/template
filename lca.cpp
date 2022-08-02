#include <cmath>
#include <vector>
using namespace std;

#define N 100001
using ll = long long;

int parent[18][N], depth[N], n, l;
vector<int> graph[N];

void dfs(int now) {
    for (int child : graph[now]) {
        if (child != parent[0][now]) {
            depth[child] = depth[now] + 1;
            parent[0][child] = now;
            dfs(child);
        }
    }
}

void build_lca() {
    parent[0][1] = 1;
    depth[1] = 0;
    dfs(1);
    l = log2(n);
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = l; i >= 0; i--) {
        if (diff & 1 << i) {
            a = parent[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = l; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}
