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

int sizz, cass;

vector<vector<int>>v(100);
vector<vector<int>>v2(100);

int len[100];

void dfs(int start)
{

	memset(len, false, sizeof(len));

	stack<int>st;
	st.push(start);
	while (!st.empty())
	{
		int cur = st.top();
		st.pop();

		for (int a = 0; a < v[cur].size(); a++)
		{
			if (len[cur] + 1 > len[v[cur][a]]) // 현재 위치로부터 다음 위치의 길이가, 다음 위치의 최대거리
				//보다 길다면 갱신
			{
				len[v[cur][a]] = len[cur] + 1;
				st.push(v[cur][a]);

			}


		}



	}

}

void dfs2(int start)
{

	memset(len, false, sizeof(len));

	stack<int>st;
	st.push(start);
	while (!st.empty())
	{
		int cur = st.top();
		st.pop();

		for (int a = 0; a < v2[cur].size(); a++)
		{
			if (len[cur] + 1 > len[v2[cur][a]]) // 현재 위치로부터 다음 위치의 길이가, 다음 위치의 최대거리
				//보다 길다면 갱신
			{
				len[v2[cur][a]] = len[cur] + 1;
				st.push(v2[cur][a]);

			}


		}



	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> sizz >> cass;




	for (int a = 0; a < cass; a++)
	{
		int b, c;
		cin >> b >> c;
		v[b].push_back(c);
		v2[c].push_back(b);
	}


	int fail = 0;


	for (int a = 1; a <= sizz; a++)
	{
		dfs(a);
		int ct = 0;
		for (int b = 1; b <= sizz; b++)
			if (len[b] > 0)
				ct++;

		if (ct > sizz / 2)
			fail++;

	}

	for (int a = 1; a <= sizz; a++)
	{
		dfs2(a);
		int ct = 0;
		for (int b = 1; b <= sizz; b++)
			if (len[b] > 0)
				ct++;

		if (ct > sizz / 2)
			fail++;

	}
	
	cout << fail;

}