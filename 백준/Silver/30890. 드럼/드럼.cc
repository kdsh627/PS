#include <iostream>

using namespace std;

int main()
{
    int X, Y; // 왼손 오른손
    cin >> X >> Y;

    int right = 0;
    int left = 0;

    //최대 반복은 큰 수 만큼
    int count = 0;
    int maxNum = max(X, Y);

    while (count < maxNum)
    {
        int nX = right + X;
        int nY = left + Y;

        //큰게 먼저 연주
        if (nX > nY)
        {
            cout << '1';
            if (X == maxNum) count++;

            left = nY;
        }
        else if (nX < nY)
        {
            cout << '2';
            if (Y == maxNum) count++;

            right = nX;
        }
        else
        {
            cout << '3';
            count++;

            right = nX;
            left = nY;
        }
    }
}