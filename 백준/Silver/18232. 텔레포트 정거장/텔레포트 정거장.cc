#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
struct INFO
{
    int node;
    int seconds;

    INFO(int n, int s) : node(n), seconds(s) {}
};

int bfs(int S, int E)
{
    queue<INFO> q;
    q.emplace(S, 0);
    visited[S] = 1;

    while (!q.empty())
    {
        INFO cur = q.front();
        q.pop();

        if (cur.node == E) 
        {
            return cur.seconds;
        }

        for (int i = 0; i < graph[cur.node].size(); ++i)
        {
            if (!visited[graph[cur.node][i]])
            {
                visited[graph[cur.node][i]] = 1;
                q.emplace(graph[cur.node][i], cur.seconds + 1);
            }
        }
    }

}

int main()
{
    int N, M, S, E; //N: 정점, S : 시작점, E : 도착점
    cin >> N >> M >> S >> E;

    visited.resize(N + 1, 0);
    graph.resize(N + 1);
    graph[1].emplace_back(2);
    graph[N].emplace_back(N-1);
    for (int i = 2; i < N ; ++i)
    {
        graph[i].emplace_back(i - 1);
        graph[i].emplace_back(i + 1);
    }

    for (int i = 0; i < M; ++i)
    {
        int x, y; //정점 x와 y는 연결되어있다.
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    cout << bfs(S, E);
}
