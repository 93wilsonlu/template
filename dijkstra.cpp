#include <queue>
#include <vector>
using namespace std;

#define N 100001
using ll = long long;

vector<pair<int, ll>> graph[N];
ll dist[N];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
int n;

void dijkstra(int start) {
    fill_n(dist + 1, n, 1e18);
    dist[start] = 0;
    q.push({0, start});
    while (!q.empty()) {
        int now = q.top().second;
        if (dist[now] != q.top().first) {
            q.pop();
            continue;
        }
        q.pop();
        for (auto [child, weight] : graph[now]) {
            if (dist[child] > dist[now] + weight) {
                dist[child] = dist[now] + weight;
                q.push({dist[child], child});
            }
        }
    }
}