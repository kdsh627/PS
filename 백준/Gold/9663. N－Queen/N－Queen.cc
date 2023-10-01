#include <iostream>
using namespace std;

int col[15];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)// 대각선이거나 같은 라인, 같은 대각선은 X-A = Y-B를 만족한다.
            return false;
    return true;
}

void queen(int deep)
{
    if (deep == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)//행, X
        {                   //deep은 고정값이므로 겹칠 수 없다, 반면 i(행)은 계속 0부터 N까지 for문이라 겹칠 수 있음
            col[deep] = i; // deep열에 i행에 퀸을 둔다는 뜻, deep = Y, col[deep] = X
            if (check(deep)) queen(deep + 1);
        }
    }
}
int main() {
    cin >> N;
    queen(0);
    cout << total;
}