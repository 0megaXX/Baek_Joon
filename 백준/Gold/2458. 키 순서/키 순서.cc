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

vector<vector<pair<int, int>>>v(1001);
int arr[501][501];
int node, want_degree;


void floyd()
{
	for (int a = 1; a <= node; a++)
	{
		for (int b = 1; b <= node; b++)
		{
			for (int c = 1; c <= node; c++)
			{
				if (arr[b][c] > arr[b][a] + arr[a][c])
					arr[b][c] = arr[b][a] + arr[a][c];
			}

		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int a = 0; a < 501; a++)
		for (int b = 0; b < 501; b++)
			arr[a][b] = MAXX;


	cin >> node >> want_degree;
	
	for (int a = 0; a < want_degree; a++)
	{
		int small, big;
		cin >> small >> big;

		arr[small][big] = 1;
	}
	
	floyd();

	int ans = 0;
	for (int a = 1; a <= node; a++)
	{
		int ct = 0;
		for (int b = 1; b <= node; b++)
		{
			if (arr[a][b] != MAXX || arr[b][a]!=MAXX)
				ct++;

		}
		if (ct == node - 1)
			ans++;
	}

	cout << ans;
}