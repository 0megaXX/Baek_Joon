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
using namespace std;


int arr[3]{ 0 };
int visit[101][101][101]{0};
int casss[6][3] = {
{9,3,1},
{9,1,3},
{3,1,9},
{3,9,1},
{1,3,9},
{1,9,3}
};
struct mutal {
	int aaa, bbb, ccc;
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	int summ = 0;
	for (int a = 0; a < cass; a++)
	{
		cin >> arr[a];

	}

	visit[arr[0]][arr[1]][arr[2]] = 0;
	queue<mutal>q;
	q.push({ arr[0],arr[1],arr[2] });


	int result = 0;
	while (!q.empty())
	{
		int aa = q.front().aaa;
		int bb = q.front().bbb;
		int cc = q.front().ccc;
		q.pop();
		
		for (int a = 0; a < 6; a++)
		{
			int rx = max(0, aa - casss[a][0]);
			int ry= max(0, bb - casss[a][1]);
			int rz= max(0, cc - casss[a][2]);

			if (visit[rx][ry][rz])
				continue;
			visit[rx][ry][rz] = visit[aa][bb][cc] + 1;
			q.push({ rx,ry,rz });


		}


	}
	cout << visit[0][0][0];


}
