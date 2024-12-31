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

using namespace std;
#define MAXX 99999999


int parent[51];

int find_pt(int a)
{
	if (parent[a] == a)
		return parent[a];
	else
		return parent[a] = find_pt(parent[a]);


}

void union_pt(int a, int b)
{

	a = find_pt(a);
	b = find_pt(b);
	if (a < b)
		parent[b] = a;

	else parent[a] = b;


}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cass;
	cin >>  cass;

	for (int a = 1; a <= cass; a++)
		parent[a] = a;

	vector < pair<int, pair<int, int>>>v;
	int total = 0; // 전체 케이블 길이 합산

	for (int a = 1; a <= cass; a++) 
	{
		string s;
		cin >> s;
		for (int b = 0; b < cass; b++) 
			if (s[b] != '0')
			{
				int len;
				if (s[b] >= 'a' && s[b] <= 'z') {
					len = s[b] - 'a' + 1;  // 'a'부터 'z'는 1부터 26
				}
				else if (s[b] >= 'A' && s[b] <= 'Z') {
					len = s[b] - 'A' + 27; // 'A'부터 'Z'는 27부터 52
				}
				v.push_back({ len, {a, b + 1} });
				total += len;
			}
		
	}

	sort(v.begin(), v.end()); // 최단거리로 정렬

	int rs = 0;
	for (int a = 0; a < v.size(); a++)
	{
		int l = v[a].second.first;
		int r = v[a].second.second;
		int len = v[a].first;

		if (find_pt(l) != find_pt(r))  //  두 집이 연결되지 않았다면
		{
			union_pt(l, r);
			rs += len;
		}
	}

	// 모든 노드가 하나의 집합으로 연결되었는지 확인
	int root = find_pt(1);
	for (int a = 2; a <= cass; a++) 
		if (find_pt(a) != root)
		{
			cout << -1;
			return 0;
		}
	

	// 사용하지 않은 케이블 길이의 합 출력
	cout << total - rs;
	return 0;

}
