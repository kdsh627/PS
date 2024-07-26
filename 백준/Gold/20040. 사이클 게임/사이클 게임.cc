#include <iostream>
using namespace std;

struct Point{ int x; int y;};

int parent[500000];
int height[500000];

void Initialize(int n)
{
    for (int i = 0; i < n; i++)
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

    int n, m;
    cin >> n >> m;
    Initialize(n);

    int a, b;
    int result = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (Find(a) == Find(b) && !result)
        {
            result = i + 1;
        }
        Union(a, b);
    }

    cout << result;
}

