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


int N, M, ans;
bool visited[501];
vector<int> v[501];

bool DFS(int cur, int parent)
{
	visited[cur] = true;
	for (auto node : v[cur]) 
	{
		if (!visited[node]) // 자식 노드를 방문안했다면
		{
			if (DFS(node, cur))  // 그 자식노드가 탐색이 가능하면
				return true;
		}
		else if (parent != node) // 리프노드가 아니라면
			 return true;
	}

	return false; // 리프노드가 아니라면
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ct = 0;
	while (1) 
	{
		ans = 0;
		cin >> N >> M;

		if (N == 0 && M == 0) // 끝나는 조건
			break;

		for (int a = 0; a < 501; a++)
			v[a].clear();

		memset(visited, false, sizeof(visited));


		for (int a = 0; a <M; a++)
		{
			int start, eend;
			cin >> start >> eend;
			v[start].push_back(eend);
			v[eend].push_back(start);
		}

		
		for (int a = 1; a <= N; a++) 
			if (!visited[a]) // 정점 a를 방문하지 않았다면
				if (!DFS(a, -1))
				{
				//	cout << a << endl;
					ans++;
				}
		

		cout << "Case " << ++ct;

		if (ans == 0) // 없다면
			cout << ": No trees.\n";

		else if (ans == 1) //하나라면
			cout << ": There is one tree.\n";

		else // 여러개면
			cout << ": A forest of " << ans << " trees.\n";

	}

	return 0;
}