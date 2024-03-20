#include<iostream>
#include<vector>

using namespace std;

int N, M; //세로, 가로
vector<vector<int>> v1;
vector<vector<int>> v2;

void initVector(vector<vector<int>>& v)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &v[i][j]);
		}
	}
}

void reverse(int y, int x)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			v2[i][j] = !v2[i][j];
		}
	}
}

int main()
{
	cin >> N >> M;
	v1.resize(N, vector<int>(M, 0));
	v2.resize(N, vector<int>(M, 0));

	initVector(v1);
	initVector(v2);


	int count = 0;
	for (int i = 0; i <= N - 3; i++)
	{
		for (int j = 0; j <= M - 3; j++)
		{
			if (v1[i][j] != v2[i][j])
			{
				count++;
				reverse(i, j);
			}
		}
	}

	bool result = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (v1[i][j] != v2[i][j]) result = false;
		}
	}

	if (result) cout << count;
	else cout << -1;

	return 0;
}