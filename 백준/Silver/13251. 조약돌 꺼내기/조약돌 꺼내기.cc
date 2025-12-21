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



int arr[51];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


	int m, k, summ = 0;
	double rs = 0.0;
	cin >> m;
	for (int a = 1; a <= m; a++) 
	{
		cin >> arr[a];
		summ += arr[a];
	}
	cin >> k;

	if (m == 1 || k == 1) 
		rs = 1.0;
	else {
		for (int a = 1; a <= m; a++) 
		{
			double tmp_prob = 1;
			int tmp_sum = summ;

			if (k > arr[a])
				continue;

			for (int b = 1; b <= k; b++) 
			{
				tmp_prob *= (double)arr[a] / tmp_sum;
				arr[a]--;
				tmp_sum--;
			}
			rs += tmp_prob;
		}
	}

	cout.precision(9);
	cout << rs;


    return 0;
}