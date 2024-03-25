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
	sort(v.begin(), v.end());

	long long summ = abs(v[1] + v[0] + v[2]);
	long long left_sl = v[1];
	long long right_sl = v[2];
	long long n_sl = v[0];


	for (int a = 0; a < len; a++)
	{
		int left = a + 1;
		int right = len - 1;
		while (left < right)
		{



			long long temp = v[left] + v[right] + v[a];

			if (abs(temp) < summ)
			{
				left_sl = v[left];
				right_sl = v[right];
				n_sl = v[a];
				summ = abs(temp);
			}

			if (temp > 0)
				right--;
			else
				left++;





		}
	}
	cout << n_sl << ' ' << left_sl << ' ' << right_sl;
}
