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



vector< pair<int, int>> col_x;
vector< pair<int, int>> col_y;
vector< pair<int, int>> col_z;
int parent[100001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>rel;


int find_parent(int x)
{
	if (parent[x] == x) // 현재 위치의 부모가 자기자신이면 더 찾을수 없음.
		return x;
	else
		return parent[x] = find_parent(parent[x]); //아니라면 최상단 부모를 찾으로 탐색.
}


void union_parent(int x, int y) 
{
	x = find_parent(x);
	y = find_parent(y);
	if (x > y)
		parent[y] = x; // 루트가 다르면 합침
	else
		parent[x] = y; // 루트가 다르면 합침
}

bool isConnected(int x, int y) // 같은 부모인가 확인 (연결여부)
{
	return 
		find_parent(x) == find_parent(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;

	col_x.resize(cass);
	col_y.resize(cass);
	col_z.resize(cass);

	for (int a = 0; a < cass; a++)
	{
		parent[a] = a;
		int x, y, z;
		cin >> x >> y >> z;
		col_x[a] = { x ,a};
		col_y[a] = { y ,a};
		col_z[a] = { z ,a};
	}


	sort(col_x.begin(), col_x.end());
	sort(col_y.begin(), col_y.end());
	sort(col_z.begin(), col_z.end());


	for (int a = 1; a < cass; a++)
	{
		
		rel.push({ abs(col_x[a].first - col_x[a - 1].first),
			{ col_x[a].second, col_x[a - 1].second} });// 간격이 가장 짧은 행성들의 x축 차이와 행성들의 번호 삽입
		
		rel.push({ abs(col_y[a].first - col_y[a - 1].first),
			{ col_y[a].second, col_y[a - 1].second} }); // 간격이 가장 짧은 행성들의 x축 차이와 행성들의 번호 삽입
		
		rel.push({ abs(col_z[a].first - col_z[a - 1].first),
			{ col_z[a].second, col_z[a - 1].second} }); // 간격이 가장 짧은 행성들의 x축 차이와 행성들의 번호 삽입
	}
	
	int summ = 0;
	int degree = 0;
	while (!rel.empty())
	{
		int one = rel.top().second.first; // 첫별
		int two = rel.top().second.second; // 다른별
		int dif = rel.top().first; // 두 별의 거리

		rel.pop();

		if (!isConnected(one, two)) // 두 별이 연결되지 않았다면
		{
			//cout<<dif<<' ' << one << ' ' << two << "연결!\n";
			union_parent(one, two);
			degree++;
			summ += dif;

		}

		if (degree == cass - 1) // 모든별이 연결되었다면
		{
			cout << summ;
			return 0;
		}

	}




}