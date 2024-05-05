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
#include <unordered_map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cass;
	cin >> cass;
	vector<int>v;
	vector<int>summ;

	for (int a = 0; a < cass; a++)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}

	for (int a = 0; a < cass; a++)
		for (int b = a; b < cass; b++)
			summ.push_back(v[a] + v[b]);
	
	sort(v.begin(), v.end());
	sort(summ.begin(), summ.end());

	
	for (int a = cass-1; a >=0; a--)
	{
		for (int b = a ; b>=0; b--)
		
			if (binary_search(summ.begin(), summ.end(), v[a] - v[b]))
			{
				cout<<v[a];
				return 0;
			}
		

	}

}