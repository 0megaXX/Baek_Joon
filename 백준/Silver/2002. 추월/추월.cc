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

map<string,int>m;
vector<int>Exit(1001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int cass;
	cin >> cass;
	for (int a = 1; a <= cass; a++)
	{
		string s;
		cin >> s;
		m[s] = a;
	}

	for (int a = 0; a < cass; a++)
	{
		string s;
		cin >> s;
		Exit[a] = m[s];

	}

	int ct = 0;
	for (int a = 0; a < cass-1; a++)
	{
		for (int b = a + 1; b < cass; b++)
		{
			if (Exit[a] > Exit[b])
			{
				ct++;
				break;
			}
		}
	}
	cout << ct;

}