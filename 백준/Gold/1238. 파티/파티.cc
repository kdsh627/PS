#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

struct INFO
{
    int node;
    int dist;
};

bool operator < (INFO a, INFO b)
{
    return a.dist > b.dist;
}

int N, M, X;
vector<vector<INFO>> graph1(1001);
vector<vector<INFO>> graph2(1001);
vector<int> dist1(1001, INF);
vector<int> dist2(1001, INF);

void dijkstra(vector<vector<INFO>> &graph, vector<int> &dist)
{
    priority_queue<INFO> pq;
    pq.push({ X, 0 });

    dist[X] = 0;

    while (!pq.empty())
    {
        INFO cur = pq.top();
        pq.pop();

        if (cur.dist != dist[cur.node]) continue;

        for (int i = 0; i < graph[cur.node].size(); ++i)
        {
            int nxtDist = cur.dist + graph[cur.node][i].dist;

            if (nxtDist < dist[graph[cur.node][i].node])
            {
                dist[graph[cur.node][i].node] = nxtDist;
                pq.push({ graph[cur.node][i].node, nxtDist });
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph1[u].push_back({ v, w });
        graph2[v].push_back({ u, w });
    }

    dijkstra(graph1, dist1);
    dijkstra(graph2, dist2);

    int max = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (max < dist1[i] + dist2[i] && dist1[i] + dist2[i] < INF) max = dist1[i] + dist2[i];
    }
    cout << max <<'\n';
}
