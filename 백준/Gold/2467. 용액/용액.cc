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




int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long>v;
	int len;
	cin >> len;
	for (int a = 0; a < len; a++)
	{
		long long b;
		cin >> b;
		v.push_back(b);
	}

	long long summ = abs(v[len - 1] + v[0]);
	long long left_sl = v[0];
	long long right_sl = v[len - 1];
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		long long temp = v[left] + v[right];

		if (abs(temp) < summ)
		{
			left_sl = v[left];
			right_sl = v[right];
			summ = abs(temp);
		}

		if (temp > 0)
			right--;
		else 
			left++;
	



	}
	cout << left_sl << ' ' << right_sl;
}
