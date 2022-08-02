#include <vector>
using namespace std;

#define N 100001
using ll = long long;

int it[N] = {};
vector<int> graph[N],path;
 
void dfs(int now) {
    while(it[now] < graph[now].size()) {
        dfs(graph[now][it[now]++]);
    }
    path.push_back(now);
}