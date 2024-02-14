#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool check[13];
int minsum = 987654321;

void cal() {
    int sum = 0;
    for (int i = 0; i < house.size(); i++) {
        int mindist = 987654321;
        for (int j = 0; j < chicken.size(); j++) {
            if (!check[j])
                continue;
            else {
                int y = abs(house[i].first - chicken[j].first);
                int x = abs(house[i].second - chicken[j].second);
                mindist = min(mindist, x + y);
            }
        }
        sum += mindist;
    }
    minsum = min(minsum, sum);
}

void select(int start, int cnt) {
    if (cnt == M) {
        cal();
        return;
    }
    else {
        for (int i = start; i < chicken.size(); i++) {
            if (!check[i]) {
                check[i] = true;
                select(i + 1, cnt + 1);
                check[i] = false;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    int info;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> info;
            if (info == 1) {
                house.push_back(make_pair(i, j));
            }
            else if (info == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    select(0, 0);
    cout << minsum;
    return 0;
}