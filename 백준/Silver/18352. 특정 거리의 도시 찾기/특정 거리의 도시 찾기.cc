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

struct Mystruct
{
	int start, end, len;
};
int MAXX = 987654321;
int city, road, target_len, start_city;
vector<vector<int>>v(300001);
vector<int>len_info(300001);
vector<int>ans;

set<int>s;

void dikstra()
{

	priority_queue<pair<int,int>,vector<pair<int, int>>,greater<>>pq;
	len_info[start_city] = 0;
	pq.push({ len_info[start_city], start_city });

	while (!pq.empty())
	{
		int cur_len = pq.top().first;
		int cur_city = pq.top().second;
		int next_len = cur_len + 1;

		if (cur_len == target_len)
		{
			//cout << cur_city << "삽입!\n";
			s.insert(cur_city);
		}

		pq.pop();

		for (int a = 0; a < v[cur_city].size(); a++)
		{
			if (next_len < len_info[v[cur_city][a]])
			{
				// << v[cur_city][a] << "까지의 최단 거리는 " << next_len << endl;
				len_info[v[cur_city][a]] = next_len;
				pq.push({ next_len ,v[cur_city][a]});
			}


		}
	}



}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);




	cin >> city >> road >> target_len >> start_city;

	for (int a = 1; a <= city; a++)
		len_info[a] = MAXX;


	for (int a = 0; a < road; a++)
	{
		int start, end;
		cin >> start >> end;
		v[start].push_back(end);
	}
	

	dikstra();

	if (s.size() == 0)
		cout << -1;
	else
		for (auto a =s.begin();a!=s.end();a++)
			cout << *a<<'\n';
}
