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

bool dp[101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string S;
	cin >> S;
	int N;
	cin >> N;
	
	vector<string>v;
	for (int a = 0; a < N; a++)
	{

		string sub;
		cin >> sub;
		v.push_back(sub);
	}

	for (int a = 0; a < S.length(); a++)
	{

		if (a == 0 || dp[a])//시작이거나 dp[a]위치까지 일치하는 경우가 존재한다면
		{

			int start = a;


			for (int b = 0; b < N; b++)
			{
				
				if (S.length() < start + v[b].length())
					continue;
				
				bool flags = true;

				for (int c = 0; c < v[b].length(); c++)
				{

					if (S[start + c] != v[b][c])
					{
						flags = false;
						break;
					}

				}
				if (flags)
					dp[start+v[b].length()] = true;


			}



		}

	}


	if (dp[S.length()])
		cout << 1;
	else
		cout << 0;

	return 0;
}