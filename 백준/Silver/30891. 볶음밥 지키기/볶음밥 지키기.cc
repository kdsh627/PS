#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct point
{
    int x, y;
};

vector<point> graph;

int main()
{
    int N, R;
    cin >> N >> R;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph.push_back({x, y});
    }

    point maxPoint;
    int maxVal = 0;

    for (int x = -100; x <= 100; ++x)
    {
        for (int y = -100; y <= 100; ++y)
        {
            int count = 0;
            for (point p : graph)
            {
                if (sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)) <= R)
                {
                    count++;
                }
            }


            if (maxVal < count)
            {
                maxVal = count;
                maxPoint = {x, y};
            }
        }
    }

    cout << maxPoint.x << ' ' << maxPoint.y;
}
