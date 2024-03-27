#include<iostream>
#include<string>
using namespace std;

void CreateNum(long long& num)
{
	string s = "0" + to_string(num);

	for (int j = 1; j < s.size(); j++)
	{
		if (s[j] <= s[j + 1]) //ex) 78 의 경우 80으로 스킵
		{
			int k = j + 1;
			if (s[j] == '9')
			{
				s[j] = '0';
				s[j - 1] += 1;
				if (s[0] > '0')
				{
					s = "0" + s;
					k = j + 2;
				}
			}
			else s[j] += 1;

			for (; k < s.size(); k++)
			{
				s[k] = '0';
			}
			j=0;
		}
	}
	num = stoll(s);
}

int main()
{
	int N;
	cin >> N;

	long long num = -1;
	for (int i = 0; i <= N; i++)
	{
		num++;
		if (num > 9876543210) {
			break;
		}

		if (num >= 10) CreateNum(num);
	}

	if (num > 9876543210) cout << -1;
	else cout << num;
}