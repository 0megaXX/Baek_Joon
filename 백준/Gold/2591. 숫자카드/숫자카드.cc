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
	#include <unordered_map>

	using namespace std;


	long long arr[50];


	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	
		string c = " ";
		string s;
		cin >> s;
		c += s;
		//int len = strlen(c);
		arr[0] = 1; arr[1] = 1;
		c[1] -= '0';
		for (int a = 2; a <= s.length(); a++)
		{
			c[a] -= '0';

			if (c[a] != 0)
				arr[a] = arr[a - 1];
			
			if ((c[a - 1] * 10) + c[a] <= 34 && c[a - 1] != 0)
				arr[a] += arr[a - 2];
			

		}

		cout << arr[s.length()];
		
	}