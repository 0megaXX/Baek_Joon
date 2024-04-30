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
#include <set>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cass;
	cin >> cass;
	while (cass--)
	{
		int cass2;
		cin >> cass2;
		cin.ignore();
		string s;
		vector<string>v;
		for (int a = 0; a < cass2; a++)
		{
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(),compare);

		set<string>seet;
		seet.insert(v[0]);
		for (int a = 1; a < cass2; a++)
		{
			string ss="";
			for (int b = 0; b < v[a].length(); b++)
			{
				ss += v[a][b];
				if (seet.find(ss) != seet.end()) // 현재 글자가 목록에 없다면
				{
					cout << "NO\n";
					goto xx;
				}


			}
			seet.insert(v[a]);
		}
		cout << "YES\n";
	xx:;

		/*for (int a = 0; a < cass2; a++)
			cout << v[a] << endl;*/

	}


}