#include <bitset>
#include <queue>
#include <vector>
using namespace std;

#define N 100001
using ll = long long;

struct Edge {
    int to;
    ll capacity;
} edges[N];

vector<int> graph[N];

ll graph[N][N] = {};
int prev_index[N], n, m;
queue<int> q;
bitset<N> visited;

ll bfs(int start, int sink) {
    while (!q.empty()) {
        q.pop();
    }
    q.push(start);
    visited.reset();
    visited[start] = 1;
    prev_index[sink] = 0;
    int now, child;
    while (!q.empty()) {
        now = q.front(), q.pop();
        if (now == sink) {
            break;
        }
        for (int index : graph[now]) {
            child = edges[index].to;
            if (edges[index].capacity && !visited[child]) {
                prev_index[child] = index;
                visited[child] = 1;
                q.push(child);
            }
        }
    }
    if (!prev_index[sink]) {
        return 0;
    }
    ll flow = 1e18;
    for (now = sink; now != start; now = prev_index[now]) {
        flow = min(flow, edges[prev_index[now]].capacity);
    }
    for (now = sink; now != start; now = prev_index[now]) {
        edges[prev_index[now]].capacity -= flow;
        edges[prev_index[now] ^ 1].capacity += flow;
    }
    return flow;
}

ll max_flow(int start, int sink) {
    ll result = 0, flow;
    while (flow = bfs(start, sink)) {
        result += flow;
    }
    return result;
}