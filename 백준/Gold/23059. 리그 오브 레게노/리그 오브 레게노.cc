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
#include <chrono>
#include <tuple>

using namespace std;
#define MAXX 2147483647



multimap<string, string> rel; // 관계
map<string, int> indegree; // 선행아이탬의 수
int item_cnt = 0;
vector<string> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
	cin >> n;

	for (int a = 0; a < n; a++) {
        
		string s1, s2;
		cin >> s1 >> s2;

		if (indegree.count(s1) == 0) // 선행이 필요 없는 아이탬이라면
        {
			item_cnt++;
			indegree.insert(make_pair(s1, 0));
		}

		if (indegree.count(s2) == 0) // 처음 등장하는 선행이 필요한 아이탬이라면
        {
			item_cnt++;
			indegree.insert(make_pair(s2, 0));
		}

		rel.insert(make_pair(s1, s2));
		indegree[s2]++; // 선행노드수 저장
	}

	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

	for (auto it = indegree.begin(); it != indegree.end(); it++) 
    {
		string item = it->first;
		if (it->second == 0) 
			pq.push(make_pair(0, item));
	}



	while (!pq.empty()) 
    {
		int cur_depth = pq.top().first;
		string cur = pq.top().second;
		pq.pop();

		result.push_back(cur);

		for (auto it = rel.lower_bound(cur); it != rel.upper_bound(cur); it++) 
        {
			string there = it->second;

			indegree[there]--;

			if (indegree[there] == 0) 
				pq.push(make_pair(cur_depth + 1, there));
			
		}
	}

	if (result.size() != item_cnt) 
		cout << -1;

	else 
		for (int a = 0; a < result.size(); a++) 
			cout << result[a] << '\n';
		
	

	return 0;
}