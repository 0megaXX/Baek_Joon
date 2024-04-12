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


map<int, int> order;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return order[a.first] < order[b.first]; 
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	int num;
	cin >> n >> c;
	map<int, int> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		m[num]++; 
		if (order[num] == 0) 
			order[num] = i + 1;
	}

	vector<pair<int, int>> vec(m.begin(), m.end()); 

	sort(vec.begin(), vec.end(), cmp); 

	for (int a = 0; a < vec.size(); a++)
		for (int b = 0; b < vec[a].second; b++) 
			cout << vec[a].first << " ";


}