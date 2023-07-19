#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxs = 0;
vector<int> graph[16];
vector<int> vT;
vector<int> vP;
void dfs(int x, int t)
{
	int tmp = t;
	tmp += vP[x];
	maxs = maxs > tmp ? maxs : tmp;
	for (int i = 0; i < graph[x].size(); i++)
	{
		dfs(graph[x][i], tmp);
	}
}
int main() {
	int N, T, P;
	cin >> N;
	vT.push_back(0);
	vP.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		vT.push_back(T);
		vP.push_back(P);
	}

	//N이 7이면 
	for (int i = 1; i <= N; i++) {
		int count = i + vT[i];
		while (count <= N) {
			if (count + vT[count] <= N + 1) { //회사에 없을 경우 거르기
				graph[i].push_back(count);
			}
			count++;
		}
	}


	for (int i = 1; i <= N; i++) {
		if (i + vT[i] <= N + 1) {
			dfs(i, 0);
		}
	}

	cout << maxs;
}