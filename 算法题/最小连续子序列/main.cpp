#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

void main()
{
	vector<int> s;
	int i = 0;
	do
	{
		cin >> i;
		s.push_back(i);
	} while (getchar() != '\n');
	//string str;
	//getline(cin,str);
	//stringstream input(str);
	//while (input >> i)
	//	s.push_back(i);
	int localmax = 0;
	int globalmax = 0;
	for (auto i : s)
	{
		localmax += i;
		if (localmax > globalmax)
			globalmax = localmax;
		if (localmax < 0)
			localmax = 0;
	}
	cout << globalmax << endl;
	system("pause");
}