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


int N, r, c;
int summ = 0;

void fn(int x, int y,int len)
{
	
	if (x == c && y == r)
	{
		cout << summ;
		return;
	}
	else if (c < x + len && r < y + len && c >= x && r >= y)
	{
		fn(x, y, len / 2);
		fn(x + len / 2, y, len / 2);
		fn(x, y + len / 2, len / 2);
		fn(x + len / 2, y + len / 2, len / 2);


	}
	else
		summ += len * len;

	


}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	fn(0, 0, pow(2, N));


}
