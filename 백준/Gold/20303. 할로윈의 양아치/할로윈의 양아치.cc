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


int parent[30001];
int childs_candy[30001];
vector<int>friends[30001];
int All_Candy[30001]{0};
int DP[30001][3001];
int Answer = 0;

int find_parent(int a)
{
	if (parent[a] == a)
		return a;
	
		return parent[a]=find_parent(parent[a]);
}


void union_parent(int a, int b)
{
	
	int a_parent = find_parent(a);
	int b_parent = find_parent(b);

	if (a_parent <= b_parent)
		parent[b_parent] = a_parent;
	else
		parent[a_parent] = b_parent;


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;


	for (int a = 1; a < 30001; a++)
		parent[a] = a;

	for (int a = 1; a <= N; a++)
		cin >> childs_candy[a];



	for (int a = 0; a < M; a++)
	{
		int child_a,child_b;
		cin >> child_a >> child_b;
		union_parent(child_a, child_b);
	}


	vector<int> Vec;
	for (int a = 1; a <= N; a++)
	{
		int b = find_parent(a);
		friends[b].push_back(a);
		Vec.push_back(b);
	}
	sort(Vec.begin(), Vec.end());
	Vec.erase(unique(Vec.begin(), Vec.end()), Vec.end());

	for (int a = 0; a < Vec.size(); a++) {
		int Rep = Vec[a];
		for (int b = 0; b < friends[Rep].size(); b++) 
			All_Candy[a] += childs_candy[friends[Rep][b]];
		
	}
	for (int a = 0; a < Vec.size(); a++) {
		int Cur = Vec[a];
		int Cnt = friends[Cur].size();
		int Candy = All_Candy[a];
		for (int b = (K - 1); b >= 0; b--) {
			if (b - Cnt >= 0) 
				DP[a + 1][b] = max(DP[a][b], DP[a][b - Cnt] + Candy);
			
			else 
				DP[a + 1][b] = DP[a][b];
			
			Answer = max(Answer, DP[a + 1][b]);
		}
	}

	cout << Answer;
}