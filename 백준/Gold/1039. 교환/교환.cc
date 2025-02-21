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
#include <tuple>

using namespace std;
#define MAXX 2147483647


int nextMaxnum[1000001][11];

int dfs(string num, int depth)
{
	if (0 == depth)
		return stoi(num);

    int currNum = stoi(num);
	int& maxnum = nextMaxnum[currNum][depth];

	if (0 <= maxnum)
		return maxnum;

	for (int a = 0; a < num.length(); a++)
		for (int b = a + 1; b < num.length(); b++)
		{
			if (0 == a && '0' == num[b]) 
				continue;

			swap(num[a], num[b]);
			maxnum = max(maxnum, dfs(num, depth - 1));
			swap(num[a], num[b]);
		}
	

	return maxnum;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
	int k;
	cin >> s >> k;
	
	memset(nextMaxnum, -1, sizeof(int) * 1000001 * 11);

    int rs = dfs(s, k);
	cout << rs;

    return 0;
   
}


