#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct INFO
{
    int y;
    int x;
    int distance;
} shark;

int N;
int sharkSize = 2;
int eatenFish = 0;
int second = 0;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<INFO> fish;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, -1, 0, 1};

bool compare(INFO a, INFO b)
{
    if (a.distance != b.distance)
    {
        return a.distance < b.distance;
    }
    else
    {
        if (a.y != b.y)
        {
            return a.y < b.y;
        }
        else
        {
            return a.x < b.x;
        }
    }
}

void bfs()
{
    queue<INFO> q;
    q.push(shark);
    visited[shark.y][shark.x] = 1;
    graph[shark.y][shark.x] = 0;

    while (!q.empty())
    {
        INFO cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;

        if (graph[y][x] > 0 && graph[y][x] < sharkSize)
        {
            fish.push_back(cur);
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (graph[ny][nx] <= sharkSize && !visited[ny][nx])
                {
                    visited[ny][nx] = 1;
                    q.push({ ny, nx, cur.distance + 1 });
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    graph.resize(N, vector<int>(N, 0));
    visited.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 9)
            {
                shark = { i, j, 0 };
            }
        }
    }

    bfs();
    while (!fish.empty())
    {
        sort(fish.begin(), fish.end(), compare);
        second += fish[0].distance;
        shark = fish[0];
        shark.distance = 0;

        eatenFish++;

        if (eatenFish == sharkSize)
        {
            sharkSize++;
            eatenFish = 0;
        }

        fill(visited.begin(), visited.end(), vector<int>(N, 0));
        fish.clear();

        bfs();
    }

    cout << second;
}
