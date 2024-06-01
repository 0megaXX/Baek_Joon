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

int stack_sum[200001];
map<string, float>Map;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	float cnt = 0;

	while (getline(cin, s)) {
		cnt++;
		if (Map.find(s) != Map.end()) 
			Map[s] += 1;
		
		else
			Map[s] = 1;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = Map.begin(); it != Map.end(); it++)
	{
		float val = (it->second / cnt) * 100;
		cout << it->first << " ";
		cout << val << endl;
	}
    
}