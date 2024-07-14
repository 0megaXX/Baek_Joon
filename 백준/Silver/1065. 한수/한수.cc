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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int N;
	cin >> N;

	int temp = N; 
	int ct = 0;
	int len = 0;
	while (temp)
	{
		len++;
		temp /= 10;
	}

	if (len < 3)
		cout << N;
	else
	{
		ct = 99;
		int h, t, o;
		for (int a = 100; a <= N; a++)
		{
			h = a / 100;
			t = (a / 10) % 10;
			o = a % 10;

			if ((h - t) == (t - o))
				ct++;
		}

		cout << ct;
	}
}
