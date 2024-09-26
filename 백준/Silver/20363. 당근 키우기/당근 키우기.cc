#include <iostream>

using namespace std;

int main()
{
	long long int X, Y;
	cin >> X >> Y; //햇빛, 수분

	//X가 10 있으면 Y 1 감소
	//Y가 10 있으면 X 1 감소
	//0이면 감소 X

	long long int result = 0;

	if (X >= Y)
	{
		result = X + Y + Y/10;
	}
	else
	{
		result = X + Y + X / 10;
	}

	cout << result;
}
