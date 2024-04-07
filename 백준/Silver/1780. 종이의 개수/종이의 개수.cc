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


using namespace std;


int arr[3000][3000];
int rs[4]{ 0 };

void fn(int x, int y,int sizz)
{
	bool complete=true;
	int start = arr[x][y];

	for (int a = x; a < x + sizz; a++)
	{
		for (int b = y; b < y + sizz; b++)
		{
			if (arr[a][b] != start)
			{
				complete = false;
				break;
			}
		}
	}

	if (!complete)
		for (int a = 0; a <= 2; a++)
			for (int b = 0; b <= 2; b++)
				fn(x + a * (sizz / 3), y + b * (sizz / 3), sizz / 3);
		
	else
		rs[start+1]++;
}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int sizz;
	cin >> sizz;
	for (int a = 1; a <= sizz; a++)
		for (int b = 1; b <= sizz; b++)
			cin >> arr[a][b];


	fn(1, 1,sizz);
	
	for (int a = 0; a < 3; a++)
		cout << rs[a] << endl;
}
