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
#include <regex>

using namespace std;
#define MAXX 2147483647

vector<int> arr(6);
vector<bool> maxFlag(6);


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int k;
	cin >> k;

	
	for (int a = 0; a < 6; a++)
	{
		int b;
		cin >> b >> arr[a];
	}

	int max1 = 0, max2 = 0; // 제일 큰 너비, 높이 구하기
	int idx1, idx2;
	for (int a = 0; a < 6; a++)
	{
		if (a % 2 == 0)
		{
			if (max1 < arr[a])
			{
				max1 = arr[a];
				idx1 = a;
			}
		}
		else
		{
			if (max2 < arr[a])
			{
				max2 = arr[a];
				idx2 = a;
			}
		}
	}

	maxFlag[idx1] = 1;
	maxFlag[idx2] = 1;

	int minus = 1;

	for (int a = 0; a < 6; a++)
	{
		if (maxFlag[a] == 1) 
			continue;
		if (a == 0)
		{
			if ((maxFlag[a + 1] | maxFlag[5]) == 0) 
				minus *= arr[a];
		}
		else if (a == 5)
		{
			if ((maxFlag[0] | maxFlag[a - 1]) == 0) 
				minus *= arr[a];
		}
		else
		{
			if ((maxFlag[a - 1] | maxFlag[a + 1]) == 0)
				minus *= arr[a];
		}
	}


	cout << (max1 * max2 - minus) * k ;

    return 0;
}