#include <iostream>

using namespace std;

int main()
{
	long long int N;
	cin >> N;

	//공비가 1보다 크고 항이 3개 이상

	bool isExit = false;
	//항이 3개 이상이므로 공비가 최대 1000000 (항의 개수와 반비례 관계)
	for (long long int r = 2; r <= 1000000; ++r)
	{
		//초기 등비 수열의 합 1, r , r^2
		long long int result = 1 + r + r*r;

		//등비수열의 합 a * (r^n - 1) / (r - 1) = N에서
		//n을 최대로하기 위해서 r과 a를 최소인 2와 1을 대입하면
		//2^n - 1 = 10^12이므로 n의 최대범위를 40으로 잡을 수 있다.  
		for (long long int k = 3; k <= 40; ++k)
		{
			if (result > N) break;
			

			//N이 (r^n - 1) / (r-1)로 나눠지면 a를 구할 수 있다(a는 정수)
			//즉, N % ((r^n - 1) / (r - 1)) = 0이면 몫이 a이다.
			if (N % result == 0)
			{
				long long int a = N / result;

				cout << k << "\n";
				for (long long int i = 0; i < k; ++i)
				{
					cout << a << ' ';
					a = a * r;
				}

				isExit = true;
				break;
			}

			result = result * r + 1;
		}
		if (isExit) break;
	}

	if (!isExit) cout << "-1";
}
