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

using namespace std;
#define MAXX 2147483647

	vector<int> fibo(46);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	fibo[0] = 0;
	fibo[1] = 1;
	for (int a = 2; a < 46; a++) 
		fibo[a] = fibo[a - 1] + fibo[a - 2];
	
	int ntest;
	cin >> ntest;
	while (ntest--) 
	{
		int num;
		cin >> num;
		vector<int> ans;
		for (int a = 45; a > 0; a--)
		{
			if (fibo[a] <= num) 
			{
				num -= fibo[a];
				ans.push_back(fibo[a]);
			}
		}
		for (int i = ans.size() - 1; i >= 0; i--) 
			cout << ans[i] << " ";
		
		cout << "\n";
	}

}

 