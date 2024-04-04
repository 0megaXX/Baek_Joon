#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
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


vector<int> son_list[100001];
int cnt[100001];



void dfs(int node, int acc) {
	cnt[node] += acc;
	for (int child : son_list[node])
	{
		//cout <<node<<"" << child << "일때 시작\n";
		dfs(child, cnt[node]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int human, rel;
	cin >> human >> rel;

	for (int a = 1; a <= human; a++)
	{
		int b;
		cin >> b;
		if (b != -1)
			son_list[b].push_back(a);
	}

	for (int a = 0; a < rel; a++)
	{
		int par, good;
		cin >> par >> good;
		cnt[par] += good;

	}
	/*for (int b = 1; b <= human; b++)
		cout << cnt[b] << ' ';
	cout << endl;
	for (int a = 1; a <= human; a++)
		if (cnt[a] > 0)
		{*/
			dfs(1, 0);
			for (int b = 1; b <= human; b++)
				cout << cnt[b] << ' ';
		/*	cout << endl;
		}*/

}
