#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int N, H; //너비, 높이

vector<int> rockBottom;
vector<int> rockTop;
vector<int> rockTotal;
int main() 
{
	cin >> N >> H;

	int rock;

	rockBottom.resize(H+1, 0);
	rockTop.resize(H+1, 0);
	rockTotal.resize(H+1, 0);

	for (int i = 0; i < N/2; i++) 
	{
		cin >> rock;
		rockBottom[rock]++;

		cin >> rock;
		rockTop[H-rock+1]++;
	}

	for (int i = H-1; i >= 1; i--)
	{
		rockBottom[i] = rockBottom[i + 1] + rockBottom[i];
	}

	for (int i = 1; i <= H; i++)
	{
		rockTop[i] = rockTop[i - 1] + rockTop[i];
	}

	int mins = 200000;
	for (int i = 1; i <= H; i++)
	{
		rockTotal[i] = rockBottom[i] + rockTop[i];
		mins = min(rockTotal[i], mins);
	}

	int count = 0;
	for (int i = 1; i <= H; i++)
	{
		if (rockTotal[i] == mins) count++;
	}

	printf("%d %d", mins, count);
}