#include <iostream>
#include <queue>
#include <algorithm>
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

vector<vector<INFO>> graph(801);
int dist[801];

int dijkstra(int s, int e)
{
    fill(dist, dist + 801, INF);
    priority_queue<INFO> pq;
    pq.push({ s, 0 });
    dist[s] = 0;

    INFO cur = { 0, 0 };
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();

        if (cur.dist != dist[cur.node]) continue;

        for (int i = 0; i < graph[cur.node].size(); ++i)
        {
            int nxt = cur.dist + graph[cur.node][i].dist;

            if (nxt < dist[graph[cur.node][i].node])
            {
                dist[graph[cur.node][i].node] = nxt;
                pq.push({ graph[cur.node][i].node, nxt });
            }
        }
    }

    return dist[e];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E;
    cin >> N >> E;

    fill(dist, dist + 801, INF);
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int v1, v2;
    cin >> v1 >> v2;

    int dist1 = dijkstra(1, v1); //A + B
    int dist2 = dijkstra(1, v2); //A + C
    int dist3 = dijkstra(v1, N); //B + N
    int dist4 = dijkstra(v2, N); //C + N
    int middle = dijkstra(v1, v2); //B + C

    vector<int> caseValue;
    caseValue.push_back(dist1 + middle + dist4);
    caseValue.push_back(dist2 + middle + dist3);

    sort(caseValue.begin(), caseValue.end());

    if (caseValue[0] >= INF)
    {
        cout << -1;
    }
    else
    {
        cout << caseValue[0];
    }
}