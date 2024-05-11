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


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq_1;
priority_queue<int>pq_2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int road;
	cin >> road;
	for (int a = 0; a < road; a++)
	{
		int GS, charge;
		cin >> GS >> charge;
		pq_1.push({ GS,charge });

	}

	int target_km, start_gas;
	cin >> target_km >> start_gas;
	int cur_km = start_gas;



	int ct = 0;
	while (!pq_1.empty())
	{
		int cur = pq_1.top().first; //현재 가야하는 거리
		int charge = pq_1.top().second; //현재 주유소에서 넣을 수 있는 가스의 양

		pq_1.pop();

		if (cur_km < cur) // 만약 가야하는 거리에 못가는 상황이라면
		{
			while (!pq_2.empty() && cur_km < cur) 
				//더이상 지나친 가게가 존재하고 현재 거리가 당장 보이는 지점보다 작다면
			{
				int add_gas = pq_2.top();
				pq_2.pop();
				cur_km += add_gas;
				ct++;
			} //위 과정은 현재 거리보다 뒤에있는 주유소 중에서 가장 많은 기름량을 충전하는 과정임
		}

		if (cur_km < cur)
		{
			cout << -1;
			return 0;
		}

		pq_2.push(charge);
		//cout << "현재거리 " << cur_km << endl;

	}


	while (!pq_2.empty() && cur_km < target_km) //더이상 지나친 가게가 존재하고 현재 거리가 목표지점을 작다면
	{
		int add_gas = pq_2.top();
		pq_2.pop();
		cur_km += add_gas;
		ct++;

	}


	if (cur_km >= target_km) //결국 목표까지 갈수 있다면
	{
		cout << ct;
		return 0;
	}

	else
		cout << -1;


}