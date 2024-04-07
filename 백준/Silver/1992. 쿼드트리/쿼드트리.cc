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
int ct[2]{ 0,0 };

int arr[64][64];

void fn(int x, int y, int sizz)
{
	bool perfect = true;

	for (int nx = x; nx < x + sizz; nx++)
	{
		for (int ny = y; ny < y + sizz; ny++)
		{
			if (arr[x][y] != arr[nx][ny])
			{
				perfect = false;
			}
		}
	}


	if (!perfect)
	{
		cout << '(';
		fn(x, y, sizz / 2);
		fn(x, y + sizz / 2, sizz / 2);
		fn(x + sizz / 2, y, sizz / 2);
		fn(x + sizz / 2, y + sizz / 2, sizz / 2);
		cout << ')';
	}
	else
		cout << arr[x][y];
	
	
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sizz;
	cin >> sizz;
	cin.ignore();

	
	for (int a = 0; a < sizz; a++)
	{
		string s;
		getline(cin, s);
		for (int b = 0; b < sizz; b++)
			 arr[a][b]=s[b]-'0';
	}
	fn(0, 0, sizz);



}
