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
#define MAX 999999999

using namespace std;



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ct;
	cin >> ct;

	int n;
	string categor, name;
	map<string, int> m;
	while (ct--)
	{
		
		cin >> n;
		while (n--)
		{
			
			cin >> name >> categor;
		
			if (m.find(categor) == m.end())
			{
				m.insert({ categor, 1 }); //없으면 1
			}
			else
				m[categor]++;              //있으면 증감
		}

		int ans = 1;
		for (auto i : m)
		{
			ans *= (i.second + 1);
		}
		ans -= 1;
		cout << ans << '\n';
		m.clear();
	}

}
