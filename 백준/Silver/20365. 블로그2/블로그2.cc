#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int countB = 0;
	int countR = 0;
	if (s[0] == 'B') countB++;
	else countR++;
	for (int i = 1; i < n; i++) { //B<R
		if (s[i] > s[i - 1]) countR++; //BR
		else if (s[i] < s[i - 1]) countB++; //RB
	}

	cout << min(countR, countB) + 1;
}