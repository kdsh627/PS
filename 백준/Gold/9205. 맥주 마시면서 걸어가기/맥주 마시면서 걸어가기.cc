#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t; //테스트 케이스 개수 (t <= 50)

struct Point
{
	int x;
	int y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	int operator - (const Point& p) const
	{
		int xDistance = (x - p.x) >= 0 ? x - p.x : p.x - x;
		int yDistance = (y - p.y) >= 0 ? y - p.y : p.y - y;

		int ManhattanDistance = xDistance + yDistance;
		return ManhattanDistance;
	}
};
vector<Point> coordinate; //좌표 모음
vector<vector<int>> graph;


void CreateGraph(int size)
{
	//그래프 초기화
	for (int i = 0; i < graph.size(); i++)
	{
		graph.clear();
	}
	graph.clear();

	graph.resize(size+1);
	for (int i = 1; i <= size; i++)
	{
		Point cur = coordinate[i];
		for (int j = 1; j <= size; j++)
		{
			if (i == j) continue;

			Point next = coordinate[j];

			if (cur - next <= 1000) graph[i].emplace_back(j);
		}
	}
}

//도착지에 도착가능한가 판별
bool CanArrive(int start, int size)
{
	queue<int> q;
	vector<bool> visited(size + 1, false);

	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];

			if (!visited[next])
			{
				if (next == size) return true;

				visited[next] = true;
				q.push(next);
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; //편의점 개수 (n <= 100)

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		int size = n + 2;

		coordinate.clear();
		coordinate.resize(size + 1);
		for (int j = 1; j <= size; j++)
		{
			cin >> coordinate[j].x >> coordinate[j].y;
		}

		CreateGraph(size);

		if (CanArrive(1, size)) cout << "happy\n";
		else cout << "sad\n";
	}
	
	return 0;
}