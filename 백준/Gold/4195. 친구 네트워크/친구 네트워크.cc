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
#define MAXX 987654321
using namespace std;


map<string, string>parent;
map<string, int>len;


string parent_find(string a) // 부모찾기
{
	if (parent[a] != a)
		return parent_find(parent[a]);
	else
		return a;
}

void union_find(string a, string b)
{

	if (a < b) // b의 부모가 더 크면
	{
		
		parent[b] = parent_find(a); // b의 부모의 부모는 a의 부모의 부모 
		len[a] += len[b];
	}
	else
	{
		parent[a] = parent_find(b);
		len[b] += len[a];
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	while (cass--)
	{
		int cass2;
		cin >> cass2;
		parent.clear();
		len.clear();

		while (cass2--)
		{
			

			string s1, s2;
			cin >> s1 >> s2;

			if (parent.find(s1) == parent.end()) // s1이 처음 등장한다면
			{
				parent[s1] = s1; // 부모를 자신으로 매핑
				len[s1] = 1; // 처음 길이는 자신 하나뿐이니 1
			}
			
			if (parent.find(s2) == parent.end()) // s2이 처음 등장한다면
			{
				parent[s2] = s2; // 부모를 자신으로 매핑
				len[s2] = 1;// 처음 길이는 자신 하나뿐이니 1
			
			}

			string s1_parent = parent_find(s1);
			string s2_parent = parent_find(s2);

			if (s1_parent != s2_parent) // 부모가 다르다면 연결
				union_find(s1_parent, s2_parent);
			
			cout << max(len[s1_parent], len[s2_parent]) << '\n';
		}
	}
}
