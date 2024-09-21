#include <iostream>
#include <vector>
#define INF 1000000
using namespace std;

vector<vector<int>> tree;
vector<int> visited;
vector<int> track;

int S, E;

int dfs(int node)
{
	visited[node] = 1;

	for (int i = 0; i < tree[node].size(); ++i)
	{
		int nxt = tree[node][i];
		
		if (!visited[nxt])
		{
			if (nxt == E)
			{
				track[node] = nxt;
				return 1;
			}

			if (dfs(nxt) == 1)
			{
				track[node] = nxt;
				return 1;
			}
		}
	}
	return 2;
}

int main()
{
	int N;
	cin >> N >> S >> E;

	track.resize(N + 1, 0);
	tree.resize(N + 1);
	visited.resize(N + 1, 0);
	for (int i = 0; i < N-1; ++i)
	{
		int s, e;
		cin >> s >> e;
		tree[s].emplace_back(e);
		tree[e].emplace_back(s);
	}

	string result = "First";

	if (dfs(S) == 2) result = "Second";
	else
	{
		int count = 1;
		int index = S;

		while (track[index] != 0)
		{
			if (count % 2 == 0)
			{
				if (tree[index].size() > 2)
				{
					result = "Second";
				}
			}

			index = track[index];
			count++;
		}
	}

	cout << result;
}
