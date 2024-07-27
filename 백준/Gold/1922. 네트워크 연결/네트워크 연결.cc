#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Node
{
	int u;
	int v;
	int w;

	bool operator <(Node n)
	{
		return w < n.w;
	}
};

vector<Node> graph;
int parent[1001];
int height[1001];

void initialize(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		height[i] = 1;
	}
}

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int A = Find(a);
	int B = Find(b);

	if (A == B) return;
	if (height[A] > height[B])
	{
		parent[B] = A;
	}
	else if (height[A] < height[B])
	{
		parent[A] = B;
	}
	else
	{
		parent[B] = A;
		height[A]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	initialize(N);
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ u, v, w });
	}
	sort(graph.begin(), graph.end());

	int result = 0;
	for (int i = 0; i < M; ++i)
	{
		Node cur = graph[i];
		if (Find(cur.u) == Find(cur.v)) continue;
		Union(cur.u, cur.v);
		result += cur.w;
	}

	cout << result;
}