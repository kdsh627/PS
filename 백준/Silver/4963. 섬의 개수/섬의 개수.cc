#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int w, h;//너비 높이

int dy[9] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dx[9] = { 1, -1, 0, 1, -1, 0, 1, -1 };

void bfs(vector<vector<int>> &graph, vector<vector<int>> &visited, int a, int b)
{
	queue<pair<int, int>> q;
	q.emplace(a, b);

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int y = cur.first + dy[i];
			int x = cur.second + dx[i];
			if (y >= 0 && y < h && x >= 0 && x < w)
			{
				if (!visited[y][x] && graph[y][x])
				{
					graph[y][x] = 0;
					visited[y][x] = 1;
					q.emplace(y, x);
				}
			}
		}
	}

}

int main() 
{
	cin >> w >> h;

	while (!(w == 0 && h == 0))
	{
		int count = 0;
		vector<vector<int>> graph(h, vector<int>(w, 0));
		vector<vector<int>> visited(h, vector<int>(w, 0));
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++) cin >> graph[y][x];
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (graph[y][x] && !visited[y][x])
				{
					bfs(graph, visited, y, x);
					count++;
				}
			}
		}

		printf("%d\n", count);
		cin >> w >> h;
	}
}