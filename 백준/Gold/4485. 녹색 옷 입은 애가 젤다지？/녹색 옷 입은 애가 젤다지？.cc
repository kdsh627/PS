#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1000000

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0 ,0 };

int graph[125][125];
int dist[125][125];

struct INFO
{
    int y;
    int x;
    int dist;
};

bool operator < (INFO a, INFO b)
{
    return a.dist > b.dist;
}

void initialize()
{
    for (int i = 0; i < 125; ++i)
    {
        fill(graph[i], graph[i] + 125, 0);
        fill(dist[i], dist[i] + 125, INF);
    }
}

int dijkstra(int N)
{
    priority_queue<INFO> pq; //node, dist
    pq.push({0, 0, graph[0][0]});
    dist[0][0] = graph[0][0];

    while (!pq.empty())
    {
        int y = pq.top().y;
        int x = pq.top().x;
        int curDist = pq.top().dist;

        pq.pop();

        if (curDist != dist[y][x]) continue;

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N)
            {
                int nxt = curDist + graph[ny][nx];

                if (nxt < dist[ny][nx])
                {
                    dist[ny][nx] = nxt;
                    pq.push({ ny, nx, nxt });
                }
            }
        }
    }

    return dist[N - 1][N - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    int N;
    cin >> N;
    while(N != 0)
    {
        initialize();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> graph[i][j];
            }
        }
        cout << "Problem " << T++ << ": " << dijkstra(N) << '\n';
        cin >> N;
    }
}
