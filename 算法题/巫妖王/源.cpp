#include<iostream>
using namespace std;

void main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int sum = n;
		int res;
		int s1 = sum / 150;
		sum = sum % 150;
		int s2 = sum / 50;
		if (s2 <= s1)
			res = sum%50;
		else
			res = sum-50*s1;
		cout << res << endl;
	}
	system("pause");
}