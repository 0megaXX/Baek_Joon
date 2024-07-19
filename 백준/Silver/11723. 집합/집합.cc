#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring> 
#include <deque>
using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sizz;
	cin >> sizz;
	cin.ignore();

	int cur = 0;
	while (sizz--)
	{
		string s;
		cin >> s;

		if (s == "add")
		{
			int num;
			cin >> num;
			cur =cur| (1 << num);
			//cin.ignore();
		}
		else if (s == "remove")
		{
			int num;
			cin >> num;
			cur &= ~(1 << num);
			//cin.ignore();
		}
		else if (s == "check")
		{
			
			int num;
			cin >> num;
			int sub = cur;
			sub|= (1 << num);
			if (cur==sub)
				cout << "1\n";
			else
				cout << "0\n";
			//cin.ignore();
		}
		else if (s == "toggle")
		{
			int num;
			cin >> num;
			cur ^= (1 << num);
			//cin.ignore();
		}
		else if (s == "all")
		{
			for(int a=1;a<=20;a++)
				cur |= (1 << a);
		}
		else if(s=="empty")
		{
			cur = 0;
		}

	}



}
