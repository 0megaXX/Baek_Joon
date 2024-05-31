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
map<string, int>Map;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cass;
	cin >> cass;
	cin.ignore();
	
		string s;
		getline(cin, s);
		stringstream ss(s);
		string sub;
		while (getline(ss, sub, ' '))
		{
			if (sub.length() >= 6 && sub.substr(sub.length() - 6, 6) == "Cheese")
				if (Map.find(sub) == Map.end())
					Map[sub]++;


		}
	
	if (Map.size() >= 4)
		cout << "yummy";
	else
		cout << "sad";
    
}