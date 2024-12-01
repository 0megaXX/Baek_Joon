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

using namespace std;
#define MAXX 99999999

int arr[250000];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, x;
	cin >> n >> x;
	int sum = 0;
	
	for (int a = 0; a < x; a++)
	{
		cin >> arr[a];
		sum += arr[a];
	}

	int ans = sum;
	int ct = 1;
	for (int a = x; a < n; a++) 
	{
		cin >> arr[a];
		sum += arr[a] - arr[a - x];
		if (sum >= ans) 
		{
			if (sum == ans) 
				ct++;
			
			else 
			{
				ans = sum;
				ct = 1;
			}
		}
	}
	if (ans == 0) 
		cout << "SAD";
	
	else
		cout << ans << '\n' << ct;
}