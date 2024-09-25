#include <iostream>

using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		arr[n]++;
	}

	long long int result = 0;
	long long int Q, T;
	for (int i = 1; i <= 100000; ++i)
	{
		for (; arr[i] > 0; arr[i]--)
		{
			Q = i; //인형 크기
			T = 1; //인형 개수

			int k = i + 1;
			while (arr[k] > 0)
			{
				Q = k; //인형 크기 재할당
				arr[k]--;
				k++; //다음 수열 검사
				T++; //개수 + 1
			}
			result += Q * T;
		}
	}
	cout << result;

}
