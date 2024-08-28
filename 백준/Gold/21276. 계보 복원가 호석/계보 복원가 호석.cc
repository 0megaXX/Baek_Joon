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

map<string, int>have_parent; // 조상이 몇명 있는지 기록
map<string, vector<string>>son_list; // 부모 밑 사람들의 배열
map<string, vector<string>>have_sons; // 자식들의 정보 기록배열
vector<string>father; // 시조 배열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass1, cass2;
	cin >> cass1;

	string s;
	vector<string>member;
	for (int a = 0; a < cass1; a++)
	{
		cin >> s;
		have_parent[s] = 0;
		member.push_back(s);
	}

	cin >> cass2;
	for (int a = 0; a < cass2; a++)
	{
		string son, parent;
		cin >> son >> parent;
		have_parent[son]++;
		son_list[parent].push_back(son);
	}


	queue<string>q;

	for (int a = 0; a < cass1; a++)
		if (have_parent[member[a]] == 0) //  시조라면
		{
			father.push_back(member[a]);
			q.push(member[a]);
		}

	int K = q.size(); // 시조의 수 기록
	cout << K << '\n';

	while (!q.empty())
	{
		string cur = q.front(); // 현재 사람
		q.pop();
		int my_son = 0; // 현재 사람의 직계자식


		if (son_list[cur].size() == 0) // 자식이 없다면
		{
			have_sons[cur];
		}

		else
			for (int a = 0; a < son_list[cur].size(); a++)
			{
				string son = son_list[cur][a];
				have_parent[son]--;

				if (have_parent[son] == 0) // 밑 사람의 조상이 더 이상 없다는 것은 현재 사람이 부모라는것
				{
					my_son++; // 마지막 조상은 가족
					have_sons[cur].push_back(son); // 현재 사람의 자식에 추가
					q.push(son); // 부모로써 q에 삽입
				}

			}

	}

	sort(father.begin(), father.end());
	for (int a = 0; a < father.size(); a++)
		cout << father[a] << ' ';
	cout << '\n';


	for (auto at : have_sons)
	{
		cout << at.first << ' ';
		cout << at.second.size() << ' ';
		sort(at.second.begin(), at.second.end());
		for (int a = 0; a < at.second.size(); a++)
			cout << at.second[a] << ' ';
		cout << '\n';

	}
}
