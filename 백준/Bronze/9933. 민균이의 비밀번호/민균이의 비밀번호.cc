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
#include <unordered_set>
#define MAXX 987654321
using namespace std;

set<string>Set;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 

	vector<string>v;
	int cass;
	cin >> cass;
	while (cass--)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int a = 0; a < v.size(); a++)
	{
		if (Set.find(v[a]) == Set.end())
		{
			Set.insert(v[a]);
		}
		else
		{
			cout << v[a].length() << ' ' << v[a][v[a].length() / 2];
			return 0;
		}

		reverse(v[a].begin(), v[a].end());
		if (Set.find(v[a]) == Set.end())
		{
			Set.insert(v[a]);
		}
		else
		{
			cout << v[a].length() << ' ' << v[a][v[a].length() / 2];
			return 0;
		}

	}
}