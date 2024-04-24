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


int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   int sizz;
	cin >> sizz;

	char c;
	for (int a = 0; a < sizz; a++) {
		for (int b = 0; b < sizz; b++)
		{
			cin >> c;
			if (c == '.')
				arr[a][b] = 1;
			else 
				arr[a][b] = 0;
		}
	}

	int cnt_row = 0;
	int row = 0;

	for (int a = 0; a < sizz; a++) 
	{
		for (int b = 0; b < sizz; b++) 
		{
			if (arr[a][b] == 1)
				cnt_row++;
			else 
				cnt_row = 0;

			if (cnt_row == 2)
				row++;
		}

		cnt_row = 0;
	}


	int col = 0;
	int cnt_col = 0;
	for (int a = 0; a < sizz; a++)
	{
		for (int b = 0; b < sizz; b++)
		{
			if (arr[b][a] == 1)
				cnt_col++;
			else
				cnt_col = 0;

			if (cnt_col == 2)
				col++;
		}

		cnt_col = 0;
	}


	cout << row << " " << col;

}