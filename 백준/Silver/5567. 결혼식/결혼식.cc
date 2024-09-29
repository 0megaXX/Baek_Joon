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


int arr[505][505];
int sizz;
int cass;

void floyd()
{

	for (int a = 0; a <= cass; a++)
		for (int b = 0; b <= cass; b++)
			for (int c = 0; c <= cass; c++)
				if(b!=c)
					arr[b][c] = min(arr[b][c], (arr[b][a] + arr[a][c]));

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	
	cin >> cass;

	for (int a = 0; a <= cass; a++)
		for (int b = 0; b <= cass; b++)
			arr[a][b] = MAXX;


	cin >> sizz;
	for (int a = 0; a < sizz; a++)
	{
		int b, c;
		cin >> b>>c;
		arr[b][c] = 1;
		arr[c][b] = 1;
	}


	floyd();

	int ct = 0;
	for (int a = 0; a <= cass; a++)
		if (arr[1][a] <= 2)
			ct++;
	
	cout << ct;
}