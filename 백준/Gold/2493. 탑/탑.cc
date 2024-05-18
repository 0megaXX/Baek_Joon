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
#include <deque>
using namespace std;

int dp[40001];
int sub[40001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	
	vector<pair<int,int>>tower;
	for (int a = 0; a < cass; a++)
	{
		int b;
		cin >> b;
		tower.push_back(make_pair(b,a+1));
	}

	stack<pair<int, int>>right_tower;
	
	right_tower.push(tower[cass - 1]); //가장 오른쪽 타워 삽입

	int* arr = new int[cass+1];
	fill(arr, arr + (cass + 1), 0);

	for (int a = cass - 2; a >= 0; a--)
	{

		while (tower[a].first >= right_tower.top().first)
		{
			arr[right_tower.top().second] = tower[a].second;
			right_tower.pop();
			if (right_tower.empty())
				break;

		}
		right_tower.push(tower[a]);



	}

	for (int a = 1; a <= cass; a++)
		cout << arr[a] << " ";




}