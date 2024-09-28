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


int arr[50][50];
int sizz;

void floyd()
{

	for (int a = 0; a < sizz; a++)
		for (int b = 0; b < sizz; b++)
			for (int c = 0; c < sizz; c++)
				if(b!=c)
					arr[b][c] = min(arr[b][c], (arr[b][a] + arr[a][c]));

}


int fn()
{
	int rs = 0;

	for (int a = 0; a < sizz; a++)
	{
		int tmp = 0;
		for (int b = 0; b < sizz; b++)
		{
			if (a != b && arr[a][b]!=MAXX && arr[a][b]<=2)
				tmp ++;
		}
		rs = max(rs, tmp);
	}
	
		return rs;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);




	cin >> sizz;

	for (int a = 0; a < sizz; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < sizz; b++)
		{
			arr[a][b] = MAXX;
			if (s[b] == 'Y')
				arr[a][b] = 1;
		}
	}


	floyd();
	cout << fn() << endl;
	/*for (int a = 0; a < sizz; a++)
	{
		for (int b = 0; b < sizz; b++)
			cout << arr[a][b] << ' ';
			cout << endl;
	}*/
}