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
#define MAXXXX 987654321
using namespace std;


int sizz,max_chicken;
int MAP[51][51];
int MAP_sub[51][51];
vector<pair<int, int>>home;
vector<pair<int, int>>chicken;
int total = MAXXXX;

void back_tracking(int start,int ct)
{
	if (ct == max_chicken)
	{
		int sub = 0;
		for (int b = 0; b < home.size(); b++)
			sub+=MAP[home[b].first][home[b].second];

		if (sub < total)
			total = sub;

		return;
	}

	for (int a = start; a < chicken.size(); a++)
	{
		vector<pair<int, pair<int, int>>>bak;
		for (int b = 0; b < home.size(); b++)
		{
			int chicken_len = abs(chicken[a].first - home[b].first)
				+ abs(chicken[a].second - home[b].second);
			int original_chicken_len = MAP[home[b].first][home[b].second];

			if (original_chicken_len > chicken_len)
			{
				bak.push_back({ original_chicken_len, {home[b].first,home[b].second} });
				MAP[home[b].first][home[b].second] = chicken_len;
			}
		}

		back_tracking(a + 1, ct+1);

		for (int b = 0; b < bak.size(); b++)
			MAP[bak[b].second.first][bak[b].second.second] = bak[b].first;


	}
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> sizz>> max_chicken;
	for(int a=0;a< sizz;a++)
		for (int b = 0; b < sizz; b++)
		{
			cin >> MAP[a][b];
			if (MAP[a][b] == 1)
			{
				MAP[a][b] = MAXXXX;
				home.push_back({ a,b });
			}
			else if (MAP[a][b] == 2)
				chicken.push_back({ a,b });
		}
	back_tracking(0, 0);
	cout<<total;
}
