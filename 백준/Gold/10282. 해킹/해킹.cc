#include <iostream>
#include <queue>
#include <algorithm>
#define INF 100000000

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

vector<vector<INFO>> graph(10001);
int dist[10001];

void dijkstra(int N, int C)
{
    priority_queue<INFO> pq;
    pq.push({C, 0});
    dist[C] = 0;

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

    int maxd = 0;
    int count = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] != INF)
        {
            count++;
            maxd = max(maxd, dist[i]);
        }
    }

    cout << count << ' ' << maxd << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n, d, c;
        cin >> n >> d >> c;
        fill(dist, dist + 10001, INF);
        for (int j = 0; j < 10001; ++j)
        {
            graph[j].clear();
        }

        for (int j = 0; j < d; ++j)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({ a, s }); //a가 b에 의존
        }
        dijkstra(n, c);
    }
}
