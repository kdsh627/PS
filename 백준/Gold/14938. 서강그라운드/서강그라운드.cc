#include <iostream>
#include <vector>
#include <queue>
#define INF 100000
using namespace std;

struct Node
{
    int e;
    int w;

    Node(int _e, int _w) : e(_e), w(_w) {}

    bool operator < (const Node& n) const
    {
        return w > n.w;
    }
};

vector<int> item;
vector<vector<Node>> graph;

void dijkstra(int X, vector<int>& dist)
{
    priority_queue<Node> pq;
    pq.push({ X, 0 });

    dist[X] = 0;

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        if (cur.w != dist[cur.e]) continue;

        for (int i = 0; i < graph[cur.e].size(); ++i)
        {
            int nxtDist = cur.w + graph[cur.e][i].w;

            if (nxtDist < dist[graph[cur.e][i].e])
            {
                dist[graph[cur.e][i].e] = nxtDist;
                pq.push({ graph[cur.e][i].e, nxtDist });
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r; //지역 개수, 수색 범위, 길의 개수
    cin >> n >> m >> r;

    item.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> item[i];
    }

    graph.resize(n + 1);
    for (int i = 0; i < r; ++i)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].emplace_back(e, w);
        graph[e].emplace_back(s, w);
    }

    int maxDist = 0;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> dist;
        dist.resize(n + 1, INF);

        dijkstra(i, dist);
        
        int totalDist = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (dist[j] <= m)
            {
                totalDist += item[j];
            }
        }
        maxDist = max(maxDist, totalDist);
    }
    
    cout << maxDist;
}