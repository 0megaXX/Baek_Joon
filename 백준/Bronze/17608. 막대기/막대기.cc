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
	int cass;
	cin >> cass;
	int cass2 = cass;
	vector<int>v;
	int a;
	while (cass--)
	{
		cin >> a;
		v.push_back(a);
	}
	int maxx = v[cass2-1];
	int ct = 1;
	for (int a = v.size() - 2; a >= 0; a--)
	{
		if (v[a] > maxx)
		{
			ct++;
			maxx = v[a];
		}
	}
	cout << ct;
}
