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

long long arr[100001];

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[0] = 0;
	int cass, want;
	cin >> cass >> want;
	for (int a = 1; a <= cass; a++)
	{
		int b;
		cin >> b;
		if (b >= want)
		{
			cout << 1;
			return 0;
		}
		arr[a] = arr[a - 1] + b;

	}

	int left = 0;
	int right = 1;
	int ct = 100000;
	 while (left!=cass)
	{
		 if (arr[right] - arr[left] < want)
		 {
			 if (right == cass)
				 break;	
			 right++;
		 }
		 else if (arr[right] - arr[left] >= want)
		{
		
			ct = min(ct, right - left);
	left++;
		}


	}
	if (ct == 100000)
		cout << 0;
	else
	cout << ct;
	
}
